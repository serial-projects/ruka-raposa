# 2025 - 2026 (C) Konigs Infrastructure Project by Ruka Raposa Team & Contrib.
# Project is under the GPLv3 license, read `LICENSE.md` for more information.

import typing

class Message:
    text: str
    level: int
    def __init__(self) -> None:
        self.text = str()
        self.level = 0

class Core:
    userdata: typing.Any
    messages: typing.List[Message]
    index: int
    limit: int

    def __init__(
        self,
        userdata: typing.Any,
        limit: int
    ) -> None:
        self.userdata = userdata
        self.messages = [Message() for _ in range(limit)]
        self.index = 0
        self.limit = limit

LEVEL_DEBUG: int = 0
LEVEL_LOG: int = 1
LEVEL_WARNING: int = 2
LEVEL_ERROR: int = 3
LEVEL_MAX: int = 1 + 1 + 1 + 1

class Validator:
    core: Core
    sinks: typing.List[typing.List[typing.Callable[[Core, Message], None]]]

    def __init__(    
        self,
        userdata: typing.Any,
        limit: int
    ) -> None:
        self.core = Core(userdata, limit)
        self.sinks = [list() for _ in range(LEVEL_MAX)]
    
    def add_listener(
        self,
        level: int,
        f: typing.Callable[[Core, Message], None]
    ) -> None:
        sink = self.sinks[level]
        sink.append(f)
    
    def message(
        self,
        level: int,
        message: str
    ) -> None:
        pass