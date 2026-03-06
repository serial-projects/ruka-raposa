#include "Progator/Backends/OG33.h"

static PG_Pointers PG_BackendsOG33Implementation = 
{
    .window_new                 = (PG_PointersWindowNew)(PG_BackendsOG33WindowNew),
    .window_destroy             = (PG_PointersWindowDestroy)(PG_BackendsOG33WindowDestroy),
    .window_construct           = (PG_PointersWindowConstruct)(PG_BackendsOG33WindowConstruct),
    .window_destruct            = (PG_PointersWindowDestruct)(PG_BackendsOG33WindowDestruct),
    .window_draw                = (PG_PointersWindowDraw)(PG_BackendsOG33WindowDraw),
    .window_set_size            = (PG_PointersWindowSetSize)(PG_BackendsOG33WindowSetSize),
    .window_set_title           = (PG_PointersWindowSetTitle)(PG_BackendsOG33WindowSetTitle),
    .renderer_new               = (PG_PointersRendererNew)(PG_BackendsOG33RendererNew),
    .renderer_destroy           = (PG_PointersRendererDestroy)(PG_BackendsOG33RendererDestroy),
    .renderer_construct         = (PG_PointersRendererConstruct)(PG_BackendsOG33RendererConstruct),
    .renderer_destruct          = (PG_PointersRendererDestruct)(PG_BackendsOG33RendererDestruct),
    .renderer_set_viewport      = (PG_PointersRendererSetViewport)(PG_BackendsOG33RendererSetViewport),
    .renderer_draw              = (PG_PointersRendererDraw)(PG_BackendsOG33RendererDraw),
    .renderer_clear             = (PG_PointersRendererClear)(PG_BackendsOG33RendererClear),
    .renderer_enable_feature    = (PG_PointersRendererEnableFeature)(PG_BackendsOG33RendererEnableFeature),
    .renderer_disable_feature   = (PG_PointersRendererDisableFeature)(PG_BackendsOG33RendererDisableFeature)
};

PG_Pointers* PG_BackendsOG33Get()
{
    return &PG_BackendsOG33Implementation;
}