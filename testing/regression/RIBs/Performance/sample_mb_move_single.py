from cgkit.ri import *

RiBegin (RI_NULL)
RiOption ("statistics","endofframe",3)

RiDisplay ("sample_mb_move_single.tif",RI_FILE,"rgba")
RiFormat (512,512,1)
RiPixelSamples (6,6)
RiShadingRate (256)
RiProjection (RI_ORTHOGRAPHIC)
RiFrameBegin (1)
RiWorldBegin ()
RiTranslate (0,0,5)
RiTransformBegin ()
RiScale (.5, .5, .5)
RiAttributeBegin ()
RiMotionBegin( [0,1] )
RiTranslate (-1,-1,0)
RiTranslate (1,1,0)
RiMotionEnd ()
RiPatch(RI_BILINEAR, P=[-1,-1,0, -1,1,0, 1,-1,0, 1,1,0])
RiAttributeEnd ()
RiTransformEnd ()
RiWorldEnd ()

RiEnd
