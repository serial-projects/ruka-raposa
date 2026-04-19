# Konigs Infrastructure by Ruka Raposa Team & Contribuitors.
# Project is under GPL3-license, read LICENSE.md on the root.

import typing
import os
import sys
import struct

# Set the version:
FAS_VERSION: str = '1.0.000'
FAS_VERSION_NUM: int = int(FAS_VERSION.replace('.', ''))

#
# FAS_Reader `Implementation`
#

class FAS_Reader:
    def init(
        self
    ) -> None:
        pass

    def close(
        self
    ) -> None:
        pass

    def get_character(
        self
    ) -> int:
        return 0

    def set_position(
        self,
        pos: int
    ) -> None:
        pass 

    def get_position(
        self
    ) -> int:
        return 0

class FAS_FileReader(FAS_Reader):
    def __init__(
        self
    ) -> None:
        self.__file_pointer: typing.Optional[typing.BinaryIO] = None
        self.__position: int = 0

    def set_file(
        self,
        fn: str
    ) -> bool:
        actual_file = None
        result: bool = True
        try:
            actual_file = open(fn, 'rb')
            self.__file_pointer = actual_file
        except:
            result = False
        return result
        
    def init(
        self
    ) -> None:
        self.__position = 0
        if self.__file_pointer:
            self.__file_pointer.seek(0, os.SEEK_CUR)
        
    def close(
        self
    ) -> None:
        self.__position = 0
        if self.__file_pointer:
            self.__file_pointer.close()
        
    def get_character(
        self
    ) -> int:
        if self.__file_pointer:
            content = self.__file_pointer.read( 1 )
            value: int = -1
            if content:		
                value = int.from_bytes(content, 'big')
                self.__position += 1
            else:
                pass
            return value
        else:
            return -1
    
    def set_position(
        self,
        pos: int
    ) -> None:
        self.__position = pos
        if self.__file_pointer:
            self.__file_pointer.seek(self.__position, os.SEEK_CUR)
    
    def get_position(
        self
    ) -> int:
        return self.__position

#
# FAS_Diagnostics `Implementation`
#

LOG_LEVEL_DEBUG: int = 1
LOG_LEVEL_MESSAGE: int = 2
LOG_LEVEL_WARNING: int = 3
LOG_LEVEL_ERROR: int = 4
LOG_LEVEL_SINK_QUANTITY: int = 1 + 1 + 1 + 1

class FAS_Diagnostics:
    class Core:
        class Message:
            """
            Contains the messages and the sink it was originally put to.
            """
            sink: int
            text: str

            def __init__(
                self
            ) -> None:
                self.sink = 0
                self.text = str()
        
        userdata: typing.Any
        messages: typing.List['FAS_Diagnostics.Core.Message']
        msg_index: int
        msg_limit: int
        code: int

        def __init__(
            self,
            msg_limit: int,
            u_data: typing.Any
        ) -> None:
            self.userdata = u_data
            self.messages = [
                FAS_Diagnostics.Core.Message()
                for _ in range(msg_limit)
            ]
            self.msg_index = 0
            self.msg_limit = msg_limit
            
            # This code should always be 0, that means `OK`.
            self.code = 0

    core: 'FAS_Diagnostics.Core'
    sinks: typing.List[typing.List[typing.Callable[['FAS_Diagnostics.Core', int, str], None]]]
    
    def __init__(
        self,
        msg_limit: int,
        u_data: typing.Any
    ) -> None:
        self.core = FAS_Diagnostics.Core(msg_limit, u_data)
        self.sinks = [list() for _ in range(LOG_LEVEL_SINK_QUANTITY)]

    def add_listener(
        self,
        level: int,
        listener: typing.Callable[['FAS_Diagnostics.Core', int, str], None],
        dump: bool
    ) -> None:
        """
        Add an listener.

        `dump` tells if all the previous messages should be dumped on
        the listener.
        """
        if dump:
            dump_quantity: int
            if self.core.msg_limit > self.core.msg_index:
                dump_quantity = self.core.msg_limit
            else:
                dump_quantity = self.core.msg_index
            for index in range(0, dump_quantity):
                grab: int = (
                    ((self.core.msg_index - 1) - index) %
                    self.core.msg_limit
                )
                m = self.core.messages[grab]
                if m.sink == level:
                    listener(
                        self.core,
                        self.core.msg_index - index,
                        m.text
                    )
        sink = self.sinks[level - 1]
        sink.append(listener)

    def write(
        self,
        level: int,
        text: str,
        code: int
    ) -> None:
        """
        NOTE: Keep in mind that the code is persistant, you need to use `.treat`
        method to remove it!
        """
        grab: int = self.core.msg_index % self.core.msg_limit
        m = self.core.messages[grab]
        m.text = text
        m.sink = level
        sink = self.sinks[level - 1]
        for listener in sink:
            listener(self.core, self.core.msg_index, text)
        # NOTE: The code is PERSISTENT:
        self.core.code = code if self.core.code == 0 else self.core.code
        self.core.msg_index = self.core.msg_index + 1
    
    def treat(
        self,
        n_code: int
    ) -> None:
        self.core.code = n_code

#
# FAS_ArgumentParser `Implementation`
#

class FAS_ArgumentParser:
    """
    Simple argument parsing tool for FAS.
    """

    class Action:
        """
        Holds the information of the parameter, this is the action itself.
        """

        wrap: typing.Callable[['FAS_ArgumentParser', typing.List[str]], bool]
        n_parameters: int
        links: typing.Tuple[str, ...]
        help: str

        def __init__(
            self,
            wrap: typing.Callable[['FAS_ArgumentParser', typing.List[str]], bool],
            n_parameters: int,
            links: typing.Tuple[str, ...],
            help: str 
        ) -> None:
            self.wrap = wrap
            self.n_parameters = n_parameters
            self.links = links
            self.help = help

        def get_help(
            self
        ) -> str:
            return f"{', '.join(self.links)}: {self.help}"

    userdata: typing.Any
    __actions: typing.Dict[str, 'FAS_ArgumentParser.Action']
    __links: typing.Dict[str, str]
    __default: typing.Optional['FAS_ArgumentParser.Action']
    __error_callback: typing.Optional[typing.Callable[['FAS_ArgumentParser',str], None]]
    __args: typing.List[str]
    __argi: int
    __running: bool

    __help_title: str
    __help_buffer: str

    def __init__(
        self,
        u_args: typing.List[str],
        u_data: typing.Any,
        help_title: str
    ) -> None:
        self.__args = u_args
        # NOTE: We always start from '1' since python includes the file!
        self.__argi = 1
        self.__actions = dict()
        self.__links = dict()
        self.__default = None
        self.userdata = u_data
        self.__help_title = help_title
        self.__help_buffer = str()
        self.__error_callback = None

        # Finally:
        self.__running = True

    def __die(
        self,
        reason: str
    ) -> None:
        if self.__error_callback:
            self.__error_callback(self, reason)
        self.__running = False

    def __perform(
        self,
        action: str
    ) -> None:
        maybe_action: 'FAS_ArgumentParser.Action' = self.__actions[action]
        if (self.__argi + maybe_action.n_parameters) > len(self.__args):
            self.__die(
                f"Parameter {self.__args[self.__argi - 1]} requires: {maybe_action.n_parameters} parameters"
            )
        else:
            self.__running = maybe_action.wrap(
                self,
                self.__args[self.__argi:self.__argi+maybe_action.n_parameters]
            )

    def __perform_default(
        self
    ) -> None:
        if self.__default:
            # Then we have the action for it:
            self.__running = self.__default.wrap(
                self,
                [self.__args[self.__argi - 1]]
            )
        else:
            # Bad error:
            self.__die(
                f"Invalid parameter: {self.__args[self.__argi - 1]}"
            )

    def step(
        self
    ) -> bool:
        if self.__running:
            if self.__argi >= len(self.__args):
                self.__running = False
            else:
                # In this case, we can get an argument:
                maybe_arg: str = self.__args[self.__argi]
                self.__argi = self.__argi + 1

                # Get the link (which points to the action).
                maybe_link: typing.Optional[str] = self.__links.get(maybe_arg)
                if maybe_link:      self.__perform(maybe_link)
                else:               self.__perform_default()
        return self.__running
    
    def add(
        self,
        action: 'FAS_ArgumentParser.Action',
        act_name: str,
        links: typing.Iterable[str]
    ) -> None:
        self.__actions[act_name] = action
        for link in links:
            self.__links[link] = act_name
        self.__help_buffer = self.__help_buffer + (action.get_help() + '\n')

    def add_default(
        self,
        action: 'FAS_ArgumentParser.Action'
    ) -> None:
        self.__default = action

    def add_error_callback(
        self,
        callback: typing.Callable[['FAS_ArgumentParser',str], None]
    ) -> None:
        self.__error_callback = callback
    
    def get_help(
        self
    ) -> str:
        return f"{self.__help_title}\n{self.__help_buffer}"

#
# FAS_Core `Definition`
#

class FAS_Core:
    """
    This is the main object passed everywhere past the definition.
    """
    class FAS_Aspects:
        """
        Holds information about the assembly aspects, like certain optimizations
        and other information about binary generation.
        """
        def __init__(
            self
        ):
            pass
    
    diagnostics: 'FAS_Diagnostics'
    source_file: typing.Optional[str]
    output_file: typing.Optional[str]
    source: typing.Optional[FAS_Reader]

    def __init__(
        self
    ) -> None:
        self.diagnostics = FAS_Diagnostics(1024, self)
        self.source_file = None
        self.output_file = None
        self.source = None
    
    def get_return_code(
        self
    ) -> int:
        return self.diagnostics.core.code

    @staticmethod
    def __diagnostics_listener_debug(
        core: 'FAS_Diagnostics.Core',
        msg_id: int,
        msg_text: str
    ) -> None:
        print(
            "[%0.8f] DEBUG: %s" % ((msg_id/core.msg_limit), msg_text)
        )
    
    @staticmethod
    def __diagnostics_listener_message(
        core: 'FAS_Diagnostics.Core',
        msg_id: int,
        msg_text: str
    ) -> None:
        print(
            "[%0.8f] MESSAGE: %s" % ((msg_id/core.msg_limit), msg_text)
        )

    @staticmethod
    def __diagnostics_listener_warning(
        core: 'FAS_Diagnostics.Core',
        msg_id: int,
        msg_text: str
    ) -> None:
        print(
            "[%0.8f] WARNING: %s" % ((msg_id/core.msg_limit), msg_text)
        )

    @staticmethod
    def __diagnostics_listener_error(
        core: 'FAS_Diagnostics.Core',
        msg_id: int,
        msg_text: str
    ) -> None:
        print(
            "[%0.8f] ERROR: %s" % ((msg_id/core.msg_limit), msg_text)
        )

    def init(
        self
    ) -> None:
        # NOTE: This is the only two sinks enabled initially.
        self.diagnostics.add_listener(
            LOG_LEVEL_MESSAGE,
            self.__diagnostics_listener_message,
            True
        )
        self.diagnostics.add_listener(
            LOG_LEVEL_WARNING,
            self.__diagnostics_listener_warning,
            True
        )
        self.diagnostics.add_listener(
            LOG_LEVEL_ERROR,
            self.__diagnostics_listener_error,
            True
        )

    def enable_debug_diagnostics(
        self
    ) -> None:
        self.diagnostics.add_listener(
            LOG_LEVEL_DEBUG,
            self.__diagnostics_listener_debug,
            True
        )

#
# FAS_Tokenizer: `Implementation`
#

class FAS_Tokenizer:
    source: 'FAS_Reader'
    line_count: int
    __max_line_height: int

    def __init__(
        self,
        source: 'FAS_Reader'
    ) -> None:
        self.source = source
        self.line_count = 0
        self.__max_line_height = 0
    
    def __incr_line(
        self
    ) -> None:
        if self.source.get_position() > self.__max_line_height:
            self.line_count = self.line_count + 1
            self.__max_line_height = self.source.get_position()

    def __getc(
        self
    ) -> typing.Optional[str]:
        v: int = self.source.get_character()
        if v == -1:
            return None
        # Continue:
        k: str = chr(v)
        if k == '\n':
            self.__incr_line()
        return k
    
    def __rewind(
        self,
        amount: int
    ) -> None:
        self.source.set_position(self.source.get_position() - amount)

    def __eat_string(
        self,
        entrypoint: str
    ) -> typing.Optional[str]:
        acc: str = entrypoint
        while True:
            ch: typing.Optional[str] = self.__getc()
            # NOTE: We don't accept an string to finish with a EOF:
            if not ch: return None
            else:
                # In this very case, then continue:
                acc = acc + ch
                if ch == entrypoint:
                    break
        return acc

    def __eat_token(
        self,
        entrypoint: str
    ) -> typing.Optional[str]:
        acc: str = entrypoint
        while True:
            ch: typing.Optional[str] = self.__getc()
            if not ch: break
            else:
                if ch in (' ', '\n', '\t', '\r'):
                    break            
                elif ch in ('\'', '"'):
                    self.__rewind(1)
                    break
                else:
                    acc = acc + ch
        return acc
    
    def __consume_line_comment(
        self
    ) -> None:
        while True:
            ch: typing.Optional[str] = self.__getc()
            if ch:
                if ch == '\n': break
            else:
                # At EOF, we break
                break

    def get(
        self
    ) -> typing.Optional[str]:
        # Check this:
        v: typing.Optional[str] = None
        while True:
            ch: typing.Optional[str] = self.__getc()
            if not ch: return None
            else:
                if ch in ('\n', '\r', '\t', ' '): continue
                elif ch in (';'):
                    self.__consume_line_comment()
                elif ch in ('\'', '"'):
                    v = self.__eat_string(ch)
                    break
                else:
                    v = self.__eat_token(ch)
                    break
        return v

#
# FAS_Operation: `Implementation`
#

FAS_OPERATION_SUPPORT_RDRS: int = 0b1000_0000
FAS_OPERATION_SUPPORT_RDIM: int = 0b0100_0000
FAS_OPERATION_SUPPORT_RD: int = 0b0010_0000
FAS_OPERATION_SUPPORT_IM: int = 0b0001_0000
FAS_OPERATION_SUPPORT_NO: int = 0b0000_0001

class FAS_Code:
    class OperationSpecification:
        name: str
        shapes: int

        def __init__(
            self,
            name: str,
            shapes: int
        ) -> None:
            self.name = name
            self.shapes = shapes

        def __str__(
            self
        ) -> str:
            return f"<operation: {self.name}, supports: {','.join( filter((lambda x: x == 'n'), [('NO' if self.shapes & FAS_OPERATION_SUPPORT_NO else 'n'), ('IM' if self.shapes & FAS_OPERATION_SUPPORT_IM else 'n'), ('RD' if self.shapes & FAS_OPERATION_SUPPORT_RD else 'n'), ('RDRS' if self.shapes & FAS_OPERATION_SUPPORT_RDRS else 'n'), ('RDIM' if self.shapes & FAS_OPERATION_SUPPORT_RDIM else 'n')]) )}>"

FAS_OPERATIONS: typing.Tuple['FAS_Code.OperationSpecification', ...] = (
    FAS_Code.OperationSpecification('mov', FAS_OPERATION_SUPPORT_RDIM | FAS_OPERATION_SUPPORT_RDRS),    # Move
    FAS_Code.OperationSpecification('nop', FAS_OPERATION_SUPPORT_NO),                                   # No Operation
    FAS_Code.OperationSpecification('swp', FAS_OPERATION_SUPPORT_RDRS),                                 # Swap
    FAS_Code.OperationSpecification('loa', FAS_OPERATION_SUPPORT_RDIM | FAS_OPERATION_SUPPORT_RDRS),    # LOAd
    FAS_Code.OperationSpecification('sto', FAS_OPERATION_SUPPORT_RDIM | FAS_OPERATION_SUPPORT_RDRS),    # STOre
    FAS_Code.OperationSpecification('add', FAS_OPERATION_SUPPORT_RDIM | FAS_OPERATION_SUPPORT_RDRS),    # Signed
    FAS_Code.OperationSpecification('sub', FAS_OPERATION_SUPPORT_RDIM | FAS_OPERATION_SUPPORT_RDRS),  
    FAS_Code.OperationSpecification('mul', FAS_OPERATION_SUPPORT_RDIM | FAS_OPERATION_SUPPORT_RDRS),  
    FAS_Code.OperationSpecification('div', FAS_OPERATION_SUPPORT_RDIM | FAS_OPERATION_SUPPORT_RDRS),
    FAS_Code.OperationSpecification('neg', FAS_OPERATION_SUPPORT_RD),                                   # NEGate an Register.
    FAS_Code.OperationSpecification('uad', FAS_OPERATION_SUPPORT_RDIM | FAS_OPERATION_SUPPORT_RDRS),    # Unsigned ADdition
    FAS_Code.OperationSpecification('usb', FAS_OPERATION_SUPPORT_RDIM | FAS_OPERATION_SUPPORT_RDRS),    # Unsigned SuBtraction
    FAS_Code.OperationSpecification('uml', FAS_OPERATION_SUPPORT_RDIM | FAS_OPERATION_SUPPORT_RDRS),  
    FAS_Code.OperationSpecification('udv', FAS_OPERATION_SUPPORT_RDIM | FAS_OPERATION_SUPPORT_RDRS),
    FAS_Code.OperationSpecification('inc', FAS_OPERATION_SUPPORT_RDRS),                                 # Signed Increment
    FAS_Code.OperationSpecification('dec', FAS_OPERATION_SUPPORT_RDRS),
    FAS_Code.OperationSpecification('ins', FAS_OPERATION_SUPPORT_RDRS),                                 # Unsigned Increment
    FAS_Code.OperationSpecification('des', FAS_OPERATION_SUPPORT_RDRS),
    FAS_Code.OperationSpecification('mod', FAS_OPERATION_SUPPORT_RDIM | FAS_OPERATION_SUPPORT_RDRS),    # MODule
    FAS_Code.OperationSpecification('bsl', FAS_OPERATION_SUPPORT_RDIM | FAS_OPERATION_SUPPORT_RDRS),    # Bit Shift Left
    FAS_Code.OperationSpecification('bsr', FAS_OPERATION_SUPPORT_RDIM | FAS_OPERATION_SUPPORT_RDRS),    # Bit Shift Right
    FAS_Code.OperationSpecification('ban', FAS_OPERATION_SUPPORT_RDIM | FAS_OPERATION_SUPPORT_RDRS),    # Bit ANd
    FAS_Code.OperationSpecification('bor', FAS_OPERATION_SUPPORT_RDIM | FAS_OPERATION_SUPPORT_RDRS),    # Bit OR
    FAS_Code.OperationSpecification('bxr', FAS_OPERATION_SUPPORT_RDIM | FAS_OPERATION_SUPPORT_RDRS),    # Bit XoR
    FAS_Code.OperationSpecification('brl', FAS_OPERATION_SUPPORT_RDIM | FAS_OPERATION_SUPPORT_RDRS),    # Bit Rotate Left
    FAS_Code.OperationSpecification('brr', FAS_OPERATION_SUPPORT_RDIM | FAS_OPERATION_SUPPORT_RDRS),    # Bit Rotate Right
    FAS_Code.OperationSpecification('bng', FAS_OPERATION_SUPPORT_RDIM | FAS_OPERATION_SUPPORT_RDRS),    # Bit NeGate
    FAS_Code.OperationSpecification('tst', FAS_OPERATION_SUPPORT_RDIM | FAS_OPERATION_SUPPORT_RDRS),    # TeST
    FAS_Code.OperationSpecification('cmp', FAS_OPERATION_SUPPORT_RDIM | FAS_OPERATION_SUPPORT_RDRS),    # CoMPare
    FAS_Code.OperationSpecification('clr', FAS_OPERATION_SUPPORT_NO),                                   # CLeaR Flags (Overflow, Equal Flag, etc)
    FAS_Code.OperationSpecification('jmp', FAS_OPERATION_SUPPORT_IM | FAS_OPERATION_SUPPORT_RD),        # JuMP (Set PC to RD/IM)
    FAS_Code.OperationSpecification('jeq', FAS_OPERATION_SUPPORT_IM | FAS_OPERATION_SUPPORT_RD),        # Jump when EQual
    FAS_Code.OperationSpecification('jnq', FAS_OPERATION_SUPPORT_IM | FAS_OPERATION_SUPPORT_RD),        # Jump when Not Equal
    FAS_Code.OperationSpecification('jgr', FAS_OPERATION_SUPPORT_IM | FAS_OPERATION_SUPPORT_RD),        # Jump when GReater
    FAS_Code.OperationSpecification('jge', FAS_OPERATION_SUPPORT_IM | FAS_OPERATION_SUPPORT_RD),        # Jump when Greater or Equal
    FAS_Code.OperationSpecification('jls', FAS_OPERATION_SUPPORT_IM | FAS_OPERATION_SUPPORT_RD),        # Jump when LeSs
    FAS_Code.OperationSpecification('jle', FAS_OPERATION_SUPPORT_IM | FAS_OPERATION_SUPPORT_RD),        # Jump when Less or Equal
    FAS_Code.OperationSpecification('bra', FAS_OPERATION_SUPPORT_IM | FAS_OPERATION_SUPPORT_RD),        # BRAnch (Push PC and set PC to RD/IM)
    FAS_Code.OperationSpecification('beq', FAS_OPERATION_SUPPORT_IM | FAS_OPERATION_SUPPORT_RD),        # Branch when EQual
    FAS_Code.OperationSpecification('bne', FAS_OPERATION_SUPPORT_IM | FAS_OPERATION_SUPPORT_RD),        # Branch when Not Equal
    FAS_Code.OperationSpecification('bgr', FAS_OPERATION_SUPPORT_IM | FAS_OPERATION_SUPPORT_RD),        # Branch when GReater
    FAS_Code.OperationSpecification('bge', FAS_OPERATION_SUPPORT_IM | FAS_OPERATION_SUPPORT_RD),        # Branch when Greater or Equal
    FAS_Code.OperationSpecification('bls', FAS_OPERATION_SUPPORT_IM | FAS_OPERATION_SUPPORT_RD),        # Branch when LeSs
    FAS_Code.OperationSpecification('ble', FAS_OPERATION_SUPPORT_IM | FAS_OPERATION_SUPPORT_RD),        # Branch when Less or Equal
    FAS_Code.OperationSpecification('ret', FAS_OPERATION_SUPPORT_NO),                                   # RETurn
    FAS_Code.OperationSpecification('psh', FAS_OPERATION_SUPPORT_IM | FAS_OPERATION_SUPPORT_RD),        # PuSH
    FAS_Code.OperationSpecification('pop', FAS_OPERATION_SUPPORT_IM | FAS_OPERATION_SUPPORT_RD),        # POP
    FAS_Code.OperationSpecification('sys', FAS_OPERATION_SUPPORT_IM | FAS_OPERATION_SUPPORT_RD),        # SYStem Call
    FAS_Code.OperationSpecification('hlt', FAS_OPERATION_SUPPORT_NO),                                   # HaLT
)

def __generate_operation_table(
    recipe: typing.Tuple['FAS_Code.OperationSpecification', ...]
) -> typing.Dict[str, int]:
    table: typing.Dict[str, int] = {
        recipe[index].name : index for index in range(0, len(recipe))
    }
    return table

FAS_OPERATION_TABLE: typing.Dict[str, int] = __generate_operation_table(
    FAS_OPERATIONS
)

print(FAS_OPERATIONS)
raise IOError("BRUH")

#
# FAS_Tree: `Implementation`
#

class FAS_Sectionizer:
    class Section:
        def __init__(
            self
        ) -> None:
            pass

    core: FAS_Core


#
# FAS_Parser: `Implementation`
#

class FAS_Parser:
    core: FAS_Core

    def __init__(
        self,
        core: FAS_Core
    ) -> None:
        self.core = core

    def parse(
        self
    ) -> None:
        """
        This requires the core to be settled down. It won't work in case you 
        didn't set the `FAS_Core.source` by the way.
        """
        tokenizer: FAS_Tokenizer = FAS_Tokenizer(
            typing.cast(FAS_Reader, self.core.source)
        )
        token: typing.Optional[str] = None
        while True:
            token = tokenizer.get()
            if token: print(token, tokenizer.line_count)
            else: break

#
# FAS_App: `The Application itself`
#

class FAS_App:
    core: 'FAS_Core'
    __ap: 'FAS_ArgumentParser'

    # NOTE: UP = User Parameter;
    @staticmethod
    def __up_debug(
        ap: 'FAS_ArgumentParser',
        parameters: typing.List[str]
    ) -> bool:
        # NOTE: We need to cast:
        core: 'FAS_Core' = typing.cast(
            'FAS_Core',
            ap.userdata
        )
        core.enable_debug_diagnostics()
        core.diagnostics.write(
            LOG_LEVEL_DEBUG,
            "Debug was enabled",
            0
        )
        return True
    
    @staticmethod
    def __up_help(
        ap: 'FAS_ArgumentParser',
        parameters: typing.List[str]
    ) -> bool:
        core: 'FAS_Core' = typing.cast(
            'FAS_Core',
            ap.userdata
        )
        # NOTE: In this case, we want to leave!
        core.diagnostics.core.code = 1
        print(ap.get_help())
        return False
    
    @staticmethod
    def __up_target(
        ap: 'FAS_ArgumentParser',
        parameters: typing.List[str]
    ) -> bool:
        # TODO: not implemented yet ;-)
        return False
    
    @staticmethod
    def __up_output(
        ap: 'FAS_ArgumentParser',
        parameters: typing.List[str]
    ) -> bool:
        core: 'FAS_Core' = typing.cast(
            'FAS_Core',
            ap.userdata
        )
        core.output_file = os.path.abspath(parameters[0])
        return False

    @staticmethod
    def __up_default(
        ap: 'FAS_ArgumentParser',
        parameters: typing.List[str]
    ) -> bool:
        if os.path.isfile(parameters[0]):
            core: 'FAS_Core' = typing.cast(
                'FAS_Core',
                ap.userdata
            )
            core.source_file = os.path.abspath(parameters[0])
        return True

    @staticmethod
    def __ap_error(
        ap: 'FAS_ArgumentParser',
        reason: str
    ) -> None:
        core: 'FAS_Core' = typing.cast(
            'FAS_Core',
            ap.userdata
        )
        core.diagnostics.write(
            LOG_LEVEL_ERROR,
            f"Error on Argument Parsing: {reason}",
            1
        )

    def __init__(
        self,
        u_args: typing.List[str]
    ) -> None:
        self.core = FAS_Core()
        self.__ap = FAS_ArgumentParser(
            u_args,
            self.core,
f"""FAS (Ferro x64 ISA Assembler) Version: {FAS_VERSION}
Python Edition, running on python {sys.version}
{'-' * (33 + 1 + len(sys.version))}

Usage:      /usr/bin/python3 fas.py [file] [parameters]
"""
        )
        self.__ap.add(
            FAS_ArgumentParser.Action(
                self.__up_debug,
                0,
                ("-d", "--debug"),
                "Enables debugging for FAS; This shows a lot of message!"
            ),
            "fas.debug_enable",
            ("-d", "--debug")
        )
        self.__ap.add(
            FAS_ArgumentParser.Action(
                self.__up_help,
                0,
                ("-h", "--help"),
                "Shows this message and quits (return 1)."
            ),
            "fas.show_help",
            ("-h", "--help")
        )
        self.__ap.add(
            FAS_ArgumentParser.Action(
                self.__up_output,
                1,
                ("-o", "--output"),
                "[<file>]; Set the output of the assembler (default is 'a.out')"
            ),
            "fas.output",
            ("-o", "--output")
        )
        self.__ap.add(
            FAS_ArgumentParser.Action(
                self.__up_target,
                1,
                ("-t", "--target"),
                "Sets an target for the assembler (possible: fe64 [default], fe32)"
            ),
            "fas.target",
            ("-t", "--target")
        )
        self.__ap.add_default(
            FAS_ArgumentParser.Action(
                self.__up_default,
                0,
                (),
                ""
            ),
        )
        self.__ap.add_error_callback(self.__ap_error)

    # Run Sequence:

    def __load_user_parameters(
        self
    ) -> int:
        while True:
            if not self.__ap.step():
                break
        self.core.diagnostics.write(
            LOG_LEVEL_DEBUG,
            "Finished parsing user arguments",
            0
        )
        return self.core.get_return_code()

    def run(
        self
    ) -> int:
        # Initialize the core:
        self.core.init()

        # Begin sequence before compiling:

        self.core.diagnostics.write(
            LOG_LEVEL_DEBUG,
            f"FAS [Python Edition] (Ferro x64 Assembler), Version: {FAS_VERSION}",
            0
        )
        self.core.diagnostics.write(
            LOG_LEVEL_DEBUG,
            f"Running on Python: {sys.version}",
            0
        )

        if self.__load_user_parameters() != 0:
            return self.core.get_return_code()
        
        # Do we have everything we need to work with?
        if not self.core.source_file:
            self.core.diagnostics.write(
                LOG_LEVEL_ERROR,
                "Nothing to do, no source file provided!",
                1
            )
            return self.core.get_return_code()
        
        # Since the target file can be omitted:
        self.core.output_file = (
            "a.out"
            if self.core.output_file == None else self.core.output_file
        )
        self.core.diagnostics.write(
            LOG_LEVEL_DEBUG,
            f"Source: {self.core.source_file}, Target: {self.core.output_file}",
            0
        )

        # Set the source on the FAS_FileReader:
        self.core.source = FAS_FileReader()
        self.core.source.set_file(self.core.source_file)

        # Set the file:
        parser: FAS_Parser = FAS_Parser(self.core)
        parser.parse()

        return self.core.get_return_code()

#
# Main Function (When executing as standalone file)
#

def main(
    args: typing.List[str]
) -> int:
    app: 'FAS_App' = FAS_App(args)
    app.run()
    return app.core.get_return_code()

if __name__ == '__main__':
    rc: int = main(
        sys.argv
    )
    # We want the program to always return to something to the system.
    exit(rc)
else:
    # NOTE: Show an important message in case you running it as a module.
    raise ImportWarning("FAS was supposed to be executed as an application!")