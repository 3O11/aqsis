from cgkit.ri import *

RiBegin (RI_NULL)
RiOption ("statistics","endofframe",3)

RiDisplay ("sample_simple.tif",RI_FILE,"rgba")
RiFormat (128,128,1)
RiShadingRate(256)
RiPixelSamples (48,48)
RiProjection (RI_ORTHOGRAPHIC)
RiFrameBegin (1)
RiWorldBegin ()
RiTranslate (0,0,5)
RiTransformBegin ()
RiScale (.66, .66, .66)
RiPatch(RI_BILINEAR, P=[-1,-1,0, -1,1,0, 1,-1,0, 1,1,0])
RiTransformEnd ()
RiWorldEnd ()

RiEnd
