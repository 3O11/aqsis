/*___________________________________________________________________________
**
** Based on Renderman Interface version 3.2
**
** Renderman Interface is Copyright (c) 1988 Pixar. All Rights reserved.
**
**___________________________________________________________________________
*/

//? Is ri.h included already?
#ifndef	RI_H_INCLUDED 
//{
#define	RI_H_INCLUDED 1

#include	"float.h"

#ifdef	__cplusplus
extern	"C"
{
#endif


	/*
	 *		RenderMan Interface Standard Include File
	 */

	/* Definitions of Abstract Types Used in RI */

	typedef	short	RtBoolean;
	typedef	int	RtInt;
	typedef	float	RtFloat;

	typedef	char	*RtToken;

	typedef	RtFloat	RtColor[ 3 ];
	typedef	RtFloat	RtPoint[ 3 ];
	typedef	RtFloat	RtMatrix[ 4 ][ 4 ];
	typedef	RtFloat	RtBasis[ 4 ][ 4 ];
	typedef	RtFloat	RtBound[ 6 ];
	typedef	char	*RtString;

	typedef	void	*RtPointer;
	typedef	void	RtVoid;

	typedef	RtFloat	( *RtFilterFunc ) ( RtFloat, RtFloat, RtFloat, RtFloat );
	typedef	RtFloat	( *RtFloatFunc ) ();
	typedef	RtVoid	( *RtFunc ) ();
	typedef	RtVoid	( *RtErrorFunc ) ( RtInt code, RtInt severity, const char * message );
	typedef	RtErrorFunc	RtErrorHandler;

	typedef	RtVoid	( *RtProcSubdivFunc ) ( RtPointer, RtFloat );
	typedef	RtVoid	( *RtProcFreeFunc ) ( RtPointer );
	typedef	RtVoid	( *RtArchiveCallback ) ( RtToken, char *, ... );

	typedef	RtPointer	RtObjectHandle;
	typedef	RtPointer	RtLightHandle;
	typedef	RtPointer	RtContextHandle;

	/* Extern Declarations for Predefined RI Data Structures */

#define	RI_FALSE	0
#define	RI_TRUE		1
#define	RI_INFINITY	FLT_MAX
#define	RI_EPSILON	FLT_EPSILON
#define	RI_NULL		((RtToken)0)

#define	RI_FLOATMIN	FLT_MIN
#define	RI_FLOATMAX	FLT_MAX

#define	RI_PI		3.14159265359f
#define	RI_PIO2		RI_PI/2

#define	RI_SHADER_EXTENSION	".slx"

	extern	RtToken	RI_FRAMEBUFFER, RI_FILE;
	extern	RtToken	RI_RGB, RI_RGBA, RI_RGBZ, RI_RGBAZ, RI_A, RI_Z, RI_AZ;
	extern	RtToken	RI_MERGE, RI_ORIGIN;
	extern	RtToken	RI_PERSPECTIVE, RI_ORTHOGRAPHIC;
	extern	RtToken	RI_HIDDEN, RI_PAINT;
	extern	RtToken	RI_CONSTANT, RI_SMOOTH;
	extern	RtToken	RI_FLATNESS, RI_FOV;

	extern	RtToken	RI_AMBIENTLIGHT, RI_POINTLIGHT,
		RI_DISTANTLIGHT, RI_SPOTLIGHT;
	extern	RtToken	RI_INTENSITY, RI_LIGHTCOLOR, RI_FROM, RI_TO,
		RI_CONEANGLE, RI_CONEDELTAANGLE,
		RI_BEAMDISTRIBUTION;
	extern	RtToken	RI_MATTE, RI_METAL, RI_PLASTIC, RI_SHINYMETAL, RI_PAINTEDPLASTIC;
	extern	RtToken	RI_KA, RI_KD, RI_KS, RI_ROUGHNESS, RI_KR,
		RI_TEXTURENAME, RI_SPECULARCOLOR;
	extern	RtToken	RI_DEPTHCUE, RI_FOG, RI_BUMPY;
	extern	RtToken	RI_MINDISTANCE, RI_MAXDISTANCE, RI_BACKGROUND,
		RI_DISTANCE, RI_AMPLITUDE;

	extern	RtToken	RI_RASTER, RI_SCREEN, RI_CAMERA, RI_WORLD,
		RI_OBJECT;
	extern	RtToken	RI_INSIDE, RI_OUTSIDE, RI_LH, RI_RH;
	extern	RtToken	RI_P, RI_PZ, RI_PW, RI_N, RI_NP, RI_CS, RI_OS,
		RI_S, RI_T, RI_ST;
	extern	RtToken	RI_BILINEAR, RI_BICUBIC;
	extern	RtToken	RI_LINEAR, RI_CUBIC;
	extern	RtToken	RI_PRIMITIVE, RI_INTERSECTION, RI_UNION,
		RI_DIFFERENCE;
	extern	RtToken	RI_WRAP, RI_NOWRAP, RI_PERIODIC, RI_NONPERIODIC, RI_CLAMP,
		RI_BLACK;
	extern	RtToken	RI_IGNORE, RI_PRINT, RI_ABORT, RI_HANDLER;
	extern	RtToken	RI_IDENTIFIER, RI_NAME;
	extern	RtToken	RI_COMMENT, RI_STRUCTURE, RI_VERBATIM;
	extern	RtToken	RI_WIDTH, RI_CONSTANTWIDTH;

	extern	RtToken	RI_CURRENT, RI_SHADER, RI_EYE, RI_NDC;

	extern	RtBasis	RiBezierBasis, RiBSplineBasis, RiCatmullRomBasis,
		RiHermiteBasis, RiPowerBasis;

#define	RI_BEZIERSTEP		((RtInt)3)
#define	RI_BSPLINESTEP		((RtInt)1)
#define	RI_CATMULLROMSTEP	((RtInt)1)
#define	RI_HERMITESTEP		((RtInt)2)
#define	RI_POWERSTEP		((RtInt)4)

	extern	RtInt	RiLastError;

	/* Declarations of All of the RenderMan Interface Subroutines */

#define	PARAMETERLIST	RtInt count, RtToken tokens[], RtPointer values[]

	RtToken	RiDeclare( const char * name, const char * declaration );

	RtVoid		RiBegin( RtToken name );
	RtVoid		RiEnd();
	RtVoid		RiFrameBegin( RtInt number );
	RtVoid		RiFrameEnd();
	RtVoid		RiWorldBegin();
	RtVoid		RiWorldEnd();

	RtVoid	RiFormat( RtInt xresolution, RtInt yresolution, RtFloat pixelaspectratio );
	RtVoid	RiFrameAspectRatio( RtFloat frameratio );
	RtVoid	RiScreenWindow( RtFloat left, RtFloat right, RtFloat bottom, RtFloat top );
	RtVoid	RiCropWindow( RtFloat left, RtFloat right, RtFloat top, RtFloat bottom );
	RtVoid	RiProjection( const char * name, ... );
	RtVoid	RiProjectionV( const char * name, PARAMETERLIST );
	RtVoid	RiClipping( RtFloat cnear, RtFloat cfar );
	RtVoid	RiDepthOfField( RtFloat fstop, RtFloat focallength, RtFloat focaldistance );
	RtVoid	RiShutter( RtFloat opentime, RtFloat closetime );

	RtVoid	RiPixelVariance( RtFloat variance );
	RtVoid	RiPixelSamples( RtFloat xsamples, RtFloat ysamples );
	RtVoid	RiPixelFilter( RtFilterFunc function, RtFloat xwidth, RtFloat ywidth );
	RtVoid	RiExposure( RtFloat gain, RtFloat gamma );
	RtVoid	RiImager( const char * name, ... );
	RtVoid	RiImagerV( const char * name, PARAMETERLIST );
	RtVoid	RiQuantize( RtToken type, RtInt one, RtInt min, RtInt max, RtFloat ditheramplitude );
	RtVoid	RiDisplay( const char * name, RtToken type, RtToken mode, ... );
	RtVoid	RiDisplayV( const char * name, RtToken type, RtToken mode, PARAMETERLIST );
	RtFloat	RiGaussianFilter( RtFloat x, RtFloat y, RtFloat xwidth, RtFloat ywidth );
	RtFloat	RiBoxFilter( RtFloat x, RtFloat y, RtFloat xwidth, RtFloat ywidth );
	RtFloat	RiTriangleFilter( RtFloat x, RtFloat y, RtFloat xwidth, RtFloat ywidth );
	RtFloat	RiCatmullRomFilter( RtFloat x, RtFloat y, RtFloat xwidth, RtFloat ywidth );
	RtFloat	RiSincFilter( RtFloat x, RtFloat y, RtFloat xwidth, RtFloat ywidth );
	RtFloat	RiDiskFilter( RtFloat x, RtFloat y, RtFloat xwidth, RtFloat ywidth );
	RtFloat	RiBesselFilter( RtFloat x, RtFloat y, RtFloat xwidth, RtFloat ywidth );

	RtVoid	RiHider( const char * name, ... );
	RtVoid	RiHiderV( const char * name, PARAMETERLIST );
	RtVoid	RiColorSamples( RtInt N, RtFloat * nRGB, RtFloat * RGBn );
	RtVoid	RiRelativeDetail( RtFloat relativedetail );
	RtVoid	RiOption( const char * name, ... );
	RtVoid	RiOptionV( const char * name, PARAMETERLIST );

	RtVoid	RiAttributeBegin();
	RtVoid	RiAttributeEnd();
	RtVoid	RiColor( RtColor Cq );
	RtVoid	RiOpacity( RtColor Os );
	RtVoid	RiTextureCoordinates( RtFloat s1, RtFloat t1,
	                             RtFloat s2, RtFloat t2,
	                             RtFloat s3, RtFloat t3,
	                             RtFloat s4, RtFloat t4 );

	RtLightHandle	RiLightSource( const char * name, ... );
	RtLightHandle	RiLightSourceV( const char * name, PARAMETERLIST );
	RtLightHandle	RiAreaLightSource( const char * name, ... );
	RtLightHandle	RiAreaLightSourceV( const char * name, PARAMETERLIST );
	RtVoid	RiIlluminate( RtLightHandle light, RtBoolean onoff );
	RtVoid	RiSurface( const char * name, ... );
	RtVoid	RiSurfaceV( const char * name, PARAMETERLIST );
	RtVoid	RiAtmosphere( const char * name, ... );
	RtVoid	RiAtmosphereV( const char * name, PARAMETERLIST );
	RtVoid	RiInterior( const char * name, ... );
	RtVoid	RiInteriorV( const char * name, PARAMETERLIST );
	RtVoid	RiExterior( const char * name, ... );
	RtVoid	RiExteriorV( const char * name, PARAMETERLIST );
	RtVoid	RiShadingRate( RtFloat size );
	RtVoid	RiShadingInterpolation( RtToken type );
	RtVoid	RiMatte( RtBoolean onoff );

	RtVoid	RiBound( RtBound bound );
	RtVoid	RiDetail( RtBound bound );
	RtVoid	RiDetailRange( RtFloat offlow, RtFloat onlow, RtFloat onhigh, RtFloat offhigh );
	RtVoid	RiGeometricApproximation( RtToken type, RtFloat value );
	RtVoid	RiOrientation( RtToken orientation );
	RtVoid	RiReverseOrientation();
	RtVoid	RiSides( RtInt nsides );

	RtVoid	RiIdentity();
	RtVoid	RiTransform( RtMatrix transform );
	RtVoid	RiConcatTransform( RtMatrix transform );
	RtVoid	RiPerspective( RtFloat fov );
	RtVoid	RiTranslate( RtFloat dx, RtFloat dy, RtFloat dz );
	RtVoid	RiRotate( RtFloat angle, RtFloat dx, RtFloat dy, RtFloat dz );
	RtVoid	RiScale( RtFloat sx, RtFloat sy, RtFloat sz );
	RtVoid	RiSkew( RtFloat angle, RtFloat dx1, RtFloat dy1, RtFloat dz1,
	               RtFloat dx2, RtFloat dy2, RtFloat dz2 );
	RtVoid	RiDeformation( const char * name, ... );
	RtVoid	RiDeformationV( const char * name, PARAMETERLIST );
	RtVoid	RiDisplacement( const char * name, ... );
	RtVoid	RiDisplacementV( const char * name, PARAMETERLIST );
	RtVoid	RiCoordinateSystem( RtToken space );
	RtPoint*	RiTransformPoints( RtToken fromspace, RtToken tospace, RtInt npoints, RtPoint points[] );
	RtVoid	RiTransformBegin();
	RtVoid	RiTransformEnd();

	RtVoid	RiAttribute( const char * name, ... );
	RtVoid	RiAttributeV( const char * name, PARAMETERLIST );

	RtVoid	RiPolygon( RtInt nvertices, ... );
	RtVoid	RiPolygonV( RtInt nvertices, PARAMETERLIST );
	RtVoid	RiGeneralPolygon( RtInt nloops, RtInt nverts[], ... );
	RtVoid	RiGeneralPolygonV( RtInt nloops, RtInt nverts[], PARAMETERLIST );
	RtVoid	RiPointsPolygons( RtInt npolys, RtInt nverts[], RtInt verts[], ... );
	RtVoid	RiPointsPolygonsV( RtInt npolys, RtInt nverts[], RtInt verts[], PARAMETERLIST );
	RtVoid	RiPointsGeneralPolygons( RtInt npolys, RtInt nloops[], RtInt nverts[], RtInt verts[], ... );
	RtVoid	RiPointsGeneralPolygonsV( RtInt npolys, RtInt nloops[], RtInt nverts[], RtInt verts[], PARAMETERLIST );
	RtVoid	RiBasis( RtBasis ubasis, RtInt ustep, RtBasis vbasis, RtInt vstep );
	RtVoid	RiPatch( RtToken type, ... );
	RtVoid	RiPatchV( RtToken type, PARAMETERLIST );
	RtVoid	RiPatchMesh( RtToken type, RtInt nu, RtToken uwrap, RtInt nv, RtToken vwrap, ... );
	RtVoid	RiPatchMeshV( RtToken type, RtInt nu, RtToken uwrap, RtInt nv, RtToken vwrap, PARAMETERLIST );
	RtVoid	RiNuPatch( RtInt nu, RtInt uorder, RtFloat uknot[], RtFloat umin, RtFloat umax,
	                  RtInt nv, RtInt vorder, RtFloat vknot[], RtFloat vmin, RtFloat vmax, ... );
	RtVoid	RiNuPatchV( RtInt nu, RtInt uorder, RtFloat uknot[], RtFloat umin, RtFloat umax,
	                   RtInt nv, RtInt vorder, RtFloat vknot[], RtFloat vmin, RtFloat vmax, PARAMETERLIST );
	RtVoid	RiTrimCurve( RtInt nloops, RtInt ncurves[], RtInt order[], RtFloat knot[], RtFloat min[], RtFloat max[], RtInt n[], RtFloat u[], RtFloat v[], RtFloat w[] );

	RtVoid	RiSphere( RtFloat radius, RtFloat zmin, RtFloat zmax, RtFloat thetamax, ... );
	RtVoid	RiSphereV( RtFloat radius, RtFloat zmin, RtFloat zmax, RtFloat thetamax, PARAMETERLIST );
	RtVoid	RiCone( RtFloat height, RtFloat radius, RtFloat thetamax, ... );
	RtVoid	RiConeV( RtFloat height, RtFloat radius, RtFloat thetamax, PARAMETERLIST );
	RtVoid	RiCylinder( RtFloat radius, RtFloat zmin, RtFloat zmax, RtFloat thetamax, ... );
	RtVoid	RiCylinderV( RtFloat radius, RtFloat zmin, RtFloat zmax, RtFloat thetamax, PARAMETERLIST );
	RtVoid	RiHyperboloid( RtPoint point1, RtPoint point2, RtFloat thetamax, ... );
	RtVoid	RiHyperboloidV( RtPoint point1, RtPoint point2, RtFloat thetamax, PARAMETERLIST );
	RtVoid	RiParaboloid( RtFloat rmax, RtFloat zmin, RtFloat zmax, RtFloat thetamax, ... );
	RtVoid	RiParaboloidV( RtFloat rmax, RtFloat zmin, RtFloat zmax, RtFloat thetamax, PARAMETERLIST );
	RtVoid	RiDisk( RtFloat height, RtFloat radius, RtFloat thetamax, ... );
	RtVoid	RiDiskV( RtFloat height, RtFloat radius, RtFloat thetamax, PARAMETERLIST );
	RtVoid	RiTorus( RtFloat majorrad, RtFloat minorrad, RtFloat phimin, RtFloat phimax, RtFloat thetamax, ... );
	RtVoid	RiTorusV( RtFloat majorrad, RtFloat minorrad, RtFloat phimin, RtFloat phimax, RtFloat thetamax, PARAMETERLIST );
	RtVoid	RiProcedural( RtPointer data, RtBound bound, RtProcSubdivFunc refineproc, RtProcFreeFunc freeproc );
	RtVoid	RiGeometry( RtToken type, ... );
	RtVoid	RiGeometryV( RtToken type, PARAMETERLIST );

	RtVoid	RiSolidBegin( RtToken type );
	RtVoid	RiSolidEnd();
	RtObjectHandle	RiObjectBegin();
	RtVoid	RiObjectEnd();
	RtVoid	RiObjectInstance( RtObjectHandle handle );
	RtVoid	RiMotionBegin( RtInt N, ... );
	RtVoid	RiMotionBeginV( RtInt N, RtFloat times[] );
	RtVoid	RiMotionEnd();

	RtVoid	RiMakeTexture( const char * imagefile, const char * texturefile, RtToken swrap, RtToken twrap, RtFilterFunc filterfunc, RtFloat swidth, RtFloat twidth, ... );
	RtVoid	RiMakeTextureV( const char * imagefile, const char * texturefile, RtToken swrap, RtToken twrap, RtFilterFunc filterfunc, RtFloat swidth, RtFloat twidth, PARAMETERLIST );
	RtVoid	RiMakeBump( const char * imagefile, const char * bumpfile, RtToken swrap, RtToken twrap, RtFilterFunc filterfunc, RtFloat swidth, RtFloat twidth, ... );
	RtVoid	RiMakeBumpV( const char * imagefile, const char * bumpfile, RtToken swrap, RtToken twrap, RtFilterFunc filterfunc, RtFloat swidth, RtFloat twidth, PARAMETERLIST );
	RtVoid	RiMakeLatLongEnvironment( const char * imagefile, const char * reflfile, RtFilterFunc filterfunc, RtFloat swidth, RtFloat twidth, ... );
	RtVoid	RiMakeLatLongEnvironmentV( const char * imagefile, const char * reflfile, RtFilterFunc filterfunc, RtFloat swidth, RtFloat twidth, PARAMETERLIST );
	RtVoid	RiMakeCubeFaceEnvironment( const char * px, const char * nx, const char * py, const char * ny, const char * pz, const char * nz, const char * reflfile, RtFloat fov, RtFilterFunc filterfunc, RtFloat swidth, RtFloat twidth, ... );
	RtVoid	RiMakeCubeFaceEnvironmentV( const char * px, const char * nx, const char * py, const char * ny, const char * pz, const char * nz, const char * reflfile, RtFloat fov, RtFilterFunc filterfunc, RtFloat swidth, RtFloat twidth, PARAMETERLIST );
	RtVoid	RiMakeShadow( const char * picfile, const char * shadowfile, ... );
	RtVoid	RiMakeShadowV( const char * picfile, const char * shadowfile, PARAMETERLIST );
	RtVoid	RiMakeOcclusion( RtInt npics, const char **picfiles, const char *shadowfile, ... );
	RtVoid	RiMakeOcclusionV( RtInt npics, const char **picfiles, const char *shadowfile, RtInt count, RtToken tokens[], RtPointer values[] );

	RtVoid	RiErrorHandler( RtErrorFunc handler );
	RtVoid	RiErrorIgnore( RtInt code, RtInt severity, const char * message );
	RtVoid	RiErrorPrint( RtInt code, RtInt severity, const char * message );
	RtVoid	RiErrorAbort( RtInt code, RtInt severity, const char * message );
	RtVoid	RiArchiveRecord( RtToken type, char *, ... );

	// ---Additional to spec. v3.1---
	RtContextHandle	RiGetContext( void );
	RtVoid	RiContext( RtContextHandle );
	RtVoid	RiClippingPlane( RtFloat, RtFloat, RtFloat, RtFloat, RtFloat, RtFloat );
	RtVoid	RiCoordSysTransform( RtToken space );
	RtVoid	RiBlobby( RtInt nleaf, RtInt ncode, RtInt code[], RtInt nflt, RtFloat flt[], RtInt nstr, RtToken str[], ... );
	RtVoid	RiBlobbyV( RtInt nleaf, RtInt ncode, RtInt code[], RtInt nflt, RtFloat flt[], RtInt nstr, RtToken str[], PARAMETERLIST );
	RtVoid	RiPoints( RtInt npoints, ... );
	RtVoid	RiPointsV( RtInt npoints, PARAMETERLIST );
	RtVoid	RiCurves( RtToken type, RtInt ncurves, RtInt nvertices[], RtToken wrap, ... );
	RtVoid	RiCurvesV( RtToken type, RtInt ncurves, RtInt nvertices[], RtToken wrap, PARAMETERLIST );
	RtVoid	RiSubdivisionMesh( RtToken scheme, RtInt nfaces, RtInt nvertices[], RtInt vertices[], RtInt ntags, RtToken tags[], RtInt nargs[], RtInt intargs[], RtFloat floatargs[], ... );
	RtVoid	RiSubdivisionMeshV( RtToken scheme, RtInt nfaces, RtInt nvertices[], RtInt vertices[], RtInt ntags, RtToken tags[], RtInt nargs[], RtInt intargs[], RtFloat floatargs[], PARAMETERLIST );

	RtVoid	RiReadArchive( RtToken name, RtArchiveCallback, ... );
	RtVoid	RiReadArchiveV( RtToken name, RtArchiveCallback, PARAMETERLIST );

	RtVoid	RiProcFree( RtPointer data );

	RtVoid	RiProcDelayedReadArchive( RtPointer data, RtFloat detail );
	RtVoid	RiProcRunProgram( RtPointer data, RtFloat detail );
	RtVoid	RiProcDynamicLoad( RtPointer data, RtFloat detail );


	// Specific to Aqsis

	typedef	RtVoid	( *RtProgressFunc ) ( RtFloat PercentComplete );

	RtBoolean	BasisFromName( RtBasis * b, const char * strName );
	RtVoid	RiProgressHandler( RtProgressFunc handler );
	RtFunc	RiPreRenderFunction( RtFunc function );

#ifdef	__cplusplus
}
#endif

/*
  Error Codes
  
   1 - 10         System and File Errors
  11 - 20         Program Limitations
  21 - 40         State Errors
  41 - 60         Parameter and Protocol Errors
  61 - 80         Execution Errors
*/
#define RIE_NOERROR     ((RtInt)0)

#define RIE_NOMEM       ((RtInt)1)      /* Out of memory */
#define RIE_SYSTEM      ((RtInt)2)      /* Miscellaneous system error */
#define RIE_NOFILE      ((RtInt)3)      /* File nonexistent */
#define RIE_BADFILE     ((RtInt)4)      /* Bad file format */
#define RIE_VERSION     ((RtInt)5)      /* File version mismatch */
#define RIE_DISKFULL    ((RtInt)6)      /* Target disk is full */

#define RIE_INCAPABLE   ((RtInt)11)     /* Optional RI feature */
#define RIE_UNIMPLEMENT ((RtInt)12)     /* Unimplemented feature */
#define RIE_LIMIT       ((RtInt)13)     /* Arbitrary program limit */
#define RIE_BUG         ((RtInt)14)     /* Probably a bug in renderer */

#define RIE_NOTSTARTED  ((RtInt)23)     /* RiBegin not called */
#define RIE_NESTING     ((RtInt)24)     /* Bad begin-end nesting */
#define RIE_NOTOPTIONS  ((RtInt)25)     /* Invalid state for options */
#define RIE_NOTATTRIBS  ((RtInt)26)     /* Invalid state for attribs */
#define RIE_NOTPRIMS    ((RtInt)27)     /* Invalid state for primitives */
#define RIE_ILLSTATE    ((RtInt)28)     /* Other invalid state */
#define RIE_BADMOTION   ((RtInt)29)     /* Badly formed motion block */
#define RIE_BADSOLID    ((RtInt)30)     /* Badly formed solid block */

#define RIE_BADTOKEN    ((RtInt)41)     /* Invalid token for request */
#define RIE_RANGE       ((RtInt)42)     /* Parameter out of range */
#define RIE_CONSISTENCY ((RtInt)43)     /* Parameters inconsistent */
#define RIE_BADHANDLE   ((RtInt)44)     /* Bad object/light handle */
#define RIE_NOSHADER    ((RtInt)45)     /* Can't load requested shader */
#define RIE_MISSINGDATA ((RtInt)46)     /* Required parameters not provided */
#define RIE_SYNTAX      ((RtInt)47)     /* Declare type syntax error */

#define RIE_MATH        ((RtInt)61)     /* Zerodivide, noninvert matrix, etc. */

/* Error severity levels */
#define RIE_INFO        ((RtInt)0)      /* Rendering stats and other info */
#define RIE_WARNING     ((RtInt)1)      /* Something seems wrong, maybe okay */
#define RIE_ERROR       ((RtInt)2)      /* Problem. Results may be wrong */
#define RIE_SEVERE      ((RtInt)3)      /* So bad you should probably abort */


//}  // End of #ifdef RI_H_INCLUDED
#endif

