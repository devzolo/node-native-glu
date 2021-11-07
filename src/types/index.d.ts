
declare module '@devzolo/node-native-glu' {
  export namespace GLU {
    /****  Generic constants ****/

    /* Version */
    const VERSION_1_1 =   1;
    const VERSION_1_2 =   1;

    /* Errors: (return value 0 = no error) */
    const INVALID_ENUM =  100900;
    const INVALID_VALUE = 100901;
    const OUT_OF_MEMORY = 100902;
    const INCOMPATIBLE_GL_VERSION =     100903;

    /* StringName */
    const VERSION =  100800;
    const EXTENSIONS = 100801;

    /* Boolean */
    const TRUE =  1;
    const FALSE = 0;


    /****  Quadric constants ****/

    /* QuadricNormal */
    const SMOOTH =   100000;
    const FLAT =  100001;
    const NONE =  100002;

    /* QuadricDrawStyle */
    const POINT = 100010;
    const LINE =  100011;
    const FILL =  100012;
    const SILHOUETTE = 100013;

    /* QuadricOrientation */
    const OUTSIDE =  100020;
    const INSIDE =   100021;

    /* Callback types: */
    /* GLU_ERROR 100103 */


    /****  Tesselation constants  ****/

    const TESS_MAX_COORD =   1.0e150;

    /* TessProperty */
    const TESS_WINDING_RULE =  100140;
    const TESS_BOUNDARY_ONLY = 100141;
    const TESS_TOLERANCE =   100142;

    /* TessWinding */
    const TESS_WINDING_ODD = 100130;
    const TESS_WINDING_NONZERO =  100131;
    const TESS_WINDING_POSITIVE = 100132;
    const TESS_WINDING_NEGATIVE = 100133;
    const TESS_WINDING_ABS_GEQ_TWO =    100134;

    /* TessCallback */
    const TESS_BEGIN = 100100  /* void (CALLBACK*)(GLenum    type)  */;
    const TESS_VERTEX =   100101  /* void (CALLBACK*)(void *data) */;
    const TESS_END = 100102  /* void (CALLBACK*)(void) */;
    const TESS_ERROR = 100103  /* void (CALLBACK*)(GLenum    errno) */;
    const TESS_EDGE_FLAG = 100104  /* void (CALLBACK*)(GLboolean boundaryEdge)  */;
    const TESS_COMBINE =  100105  /* void (CALLBACK*)(GLdouble  coords[3],    void *data[4],    GLfloat   weight[4],    void **dataOut)     */;
    const TESS_BEGIN_DATA =     100106  /* void (CALLBACK*)(GLenum    type,    void *polygon_data) */;
    const TESS_VERTEX_DATA =    100107  /* void (CALLBACK*)(void *data,    void *polygon_data) */;
    const TESS_END_DATA = 100108  /* void (CALLBACK*)(void *polygon_data) */;
    const TESS_ERROR_DATA =     100109  /* void (CALLBACK*)(GLenum    errno,    void *polygon_data) */;
    const TESS_EDGE_FLAG_DATA = 100110  /* void (CALLBACK*)(GLboolean boundaryEdge,    void *polygon_data) */;
    const TESS_COMBINE_DATA =   100111  /* void (CALLBACK*)(GLdouble  coords[3],    void *data[4],    GLfloat   weight[4],    void **dataOut,    void *polygon_data) */;

    /* TessError */
    const TESS_ERROR1 =     100151;
    const TESS_ERROR2 =     100152;
    const TESS_ERROR3 =     100153;
    const TESS_ERROR4 =     100154;
    const TESS_ERROR5 =     100155;
    const TESS_ERROR6 =     100156;
    const TESS_ERROR7 =     100157;
    const TESS_ERROR8 =     100158;

    const TESS_MISSING_BEGIN_POLYGON =  100151;
    const TESS_MISSING_BEGIN_CONTOUR =  100152;
    const TESS_MISSING_END_POLYGON =    100153;
    const TESS_MISSING_END_CONTOUR =    100154;
    const TESS_COORD_TOO_LARGE =  100155;
    const TESS_NEED_COMBINE_CALLBACK =  100156;

    /****  NURBS constants   ****/

    /* NurbsProperty */
    const AUTO_LOAD_MATRIX =    100200;
    const CULLING =  100201;
    const SAMPLING_TOLERANCE =  100203;
    const DISPLAY_MODE =  100204;
    const PARAMETRIC_TOLERANCE =  100202;
    const SAMPLING_METHOD =  100205;
    const U_STEP =  100206;
    const V_STEP =  100207;

    /* NurbsSampling */
    const PATH_LENGTH =   100215;
    const PARAMETRIC_ERROR = 100216;
    const DOMAIN_DISTANCE =  100217;


    /* NurbsTrim */
    const MAP1_TRIM_2 =   100210;
    const MAP1_TRIM_3 =   100211;

    /* NurbsDisplay */
    /* GLU_FILL  100012 */
    const OUTLINE_POLYGON =     100240;
    const OUTLINE_PATCH = 100241;

    /* NurbsCallback */
    /* GLU_ERROR 100103 */

    /* NurbsErrors */
    const NURBS_ERROR1 =  100251;
    const NURBS_ERROR2 =  100252;
    const NURBS_ERROR3 =  100253;
    const NURBS_ERROR4 =  100254;
    const NURBS_ERROR5 =  100255;
    const NURBS_ERROR6 =  100256;
    const NURBS_ERROR7 =  100257;
    const NURBS_ERROR8 =  100258;
    const NURBS_ERROR9 =  100259;
    const NURBS_ERROR10 = 100260;
    const NURBS_ERROR11 = 100261;
    const NURBS_ERROR12 = 100262;
    const NURBS_ERROR13 = 100263;
    const NURBS_ERROR14 = 100264;
    const NURBS_ERROR15 = 100265;
    const NURBS_ERROR16 = 100266;
    const NURBS_ERROR17 = 100267;
    const NURBS_ERROR18 = 100268;
    const NURBS_ERROR19 = 100269;
    const NURBS_ERROR20 = 100270;
    const NURBS_ERROR21 = 100271;
    const NURBS_ERROR22 = 100272;
    const NURBS_ERROR23 = 100273;
    const NURBS_ERROR24 = 100274;
    const NURBS_ERROR25 = 100275;
    const NURBS_ERROR26 = 100276;
    const NURBS_ERROR27 = 100277;
    const NURBS_ERROR28 = 100278;
    const NURBS_ERROR29 = 100279;
    const NURBS_ERROR30 = 100280;
    const NURBS_ERROR31 = 100281;
    const NURBS_ERROR32 = 100282;
    const NURBS_ERROR33 = 100283;
    const NURBS_ERROR34 = 100284;
    const NURBS_ERROR35 = 100285;
    const NURBS_ERROR36 = 100286;
    const NURBS_ERROR37 = 100287;

    /* Contours types -- obsolete! */
    const CW = 100120;
    const CCW =   100121;
    const INTERIOR =    100122;
    const EXTERIOR =    100123;
    const UNKNOWN =     100124;

    /* Names without "TESS_" prefix */
    const BEGIN = 100100;
    const VERTEX = 100101;
    const END =   100102;
    const ERROR = 100103;
    const EDGE_FLAG =   100104;

    type GLUquadricPtr = number;
    type GLUnurbsPtr = number;
    type GLdouble = number;
    type GLUtesselatorPtr = number;

    function errorString (errCode: GLenum): string;
    function errorUnicodeString(errCode: GLenum): string;
    function getString (name: GLenum): string;
    function ortho2D(left: GLdouble ,right: GLdouble ,bottom: GLdouble ,top: GLdouble ): void;
    function perspective(fovy: GLdouble ,aspect: GLdouble ,zNear: GLdouble ,zFar: GLdouble ): void;
    function pickMatrix(x: GLdouble ,y: GLdouble ,width: GLdouble ,height: GLdouble , viewport:GLint[]): void;
    function lookAt(eyex: GLdouble ,eyey: GLdouble ,eyez: GLdouble ,centerx: GLdouble ,centery: GLdouble ,centerz: GLdouble ,upx: GLdouble ,upy: GLdouble ,upz: GLdouble ): void;
    function project( objx: GLdouble , objy: GLdouble , objz: GLdouble , modelMatrix: GLdouble[], projMatrix: GLdouble [], viewport: GLint[], winx: GLdouble , winy: GLdouble , winz: GLdouble ): number;
    function unProject(winx: GLdouble ,winy: GLdouble ,winz: GLdouble , modelMatrix: GLdouble[], projMatrix: GLdouble [], viewport: GLint[], objx: GLdouble, objy: GLdouble, objz: GLdouble): number;
    function scaleImage(format:  GLenum ,widthin: GLint ,heightin: GLint ,typein:  GLenum , datain: GLdouble[],widthout: GLint ,heightout: GLint ,typeout:  GLenum , dataout: GLdouble[]): number;
    function build1DMipmaps(target:  GLenum ,components: GLint ,width: GLint ,format:  GLenum ,type:  GLenum , data: GLdouble[]): number;
    function build2DMipmaps(target:  GLenum ,components: GLint ,width: GLint ,height: GLint ,format:  GLenum ,type:  GLenum , data: GLdouble[]): number;
    function newQuadric(): GLUquadricPtr;
    function deleteQuadric (state: GLUquadricPtr): void;
    function quadricNormals(quadObject: GLUquadricPtr, normals: GLenum ): void;
    function quadricTexture (quadObject: GLUquadricPtr, textureCoords: GLboolean ): void;
    function quadricOrientation(quadObject: GLUquadricPtr ,orientation:  GLenum ): void;
    function quadricDrawStyle(quadObject: GLUquadricPtr ,drawStyle:  GLenum ): void;
    function cylinder(qobj: GLUquadricPtr ,baseRadius: GLdouble ,topRadius: GLdouble ,height: GLdouble ,slices: GLint ,stacks: GLint ): void;
    function disk(qobj: GLUquadricPtr ,innerRadius: GLdouble ,outerRadius: GLdouble ,slices: GLint ,loops: GLint ): void;
    function partialDisk(qobj: GLUquadricPtr ,innerRadius: GLdouble ,outerRadius: GLdouble ,slices: GLint ,loops: GLint ,startAngle: GLdouble ,sweepAngle: GLdouble ): void;
    function sphere(qobj: GLUquadricPtr ,radius: GLdouble ,slices: GLint ,stacks: GLint ): void;
    function quadricCallback(qobj: GLUquadricPtr ,  which:  GLenum , cb: () => void): void;
    function newTess(): GLUtesselatorPtr;
    function deleteTess( tess: GLUtesselatorPtr  ): void;
    function tessBeginPolygon( tess: GLUtesselatorPtr , polygon_data:GLdouble[]): void;
    function tessBeginContour( tess: GLUtesselatorPtr  ): void;
    function tessVertex( tess: GLUtesselatorPtr ,coords: GLdouble[], data:GLdouble[] ): void;
    function tessEndContour( tess: GLUtesselatorPtr  ): void;
    function tessEndPolygon( tess: GLUtesselatorPtr  ): void;
    function tessProperty( tess: GLUtesselatorPtr ,  which:  GLenum ,value: GLdouble  ): void;
    function tessNormal( tess: GLUtesselatorPtr ,x: GLdouble ,y: GLdouble ,z: GLdouble  ): void;
    function tessCallback( tess: GLUtesselatorPtr ,  which:  GLenum , cb: () => void): void;
    function getTessProperty( tess: GLUtesselatorPtr ,  which:  GLenum): GLdouble
    function newNurbsRenderer (): GLUnurbsPtr;
    function deleteNurbsRenderer( nobj: GLUnurbsPtr ): void;
    function beginSurface( nobj: GLUnurbsPtr ): void;
    function beginCurve( nobj: GLUnurbsPtr ): void;
    function endCurve( nobj: GLUnurbsPtr ): void;
    function endSurface( nobj: GLUnurbsPtr ): void;
    function beginTrim( nobj: GLUnurbsPtr ): void;
    function endTrim( nobj: GLUnurbsPtr ): void;
    function pwlCurve( nobj: GLUnurbsPtr ,count: GLint , array:GLfloat[],stride: GLint , type: GLenum ): void;
    function nurbsCurve( nobj: GLUnurbsPtr ,nknots: GLint , knot: GLfloat,stride: GLint , ctlarray: GLfloat, order: GLint ,  type:  GLenum ): void;
    function nurbsSurface( nobj: GLUnurbsPtr ,sknot_count: GLint , sknot: number,tknot_count: GLint ,   tknot: GLfloat,s_stride: GLint ,t_stride: GLint , ctlarray: GLfloat,sorder: GLint ,torder: GLint ,  type:  GLenum ): void;
    function loadSamplingMatrices( nobj: GLUnurbsPtr , modelMatrix: GLfloat[], projMatrix: GLfloat[], viewport: GLint [] ): void;
    function nurbsProperty( nobj: GLUnurbsPtr , property: GLenum , value: GLfloat ): void;
    function getNurbsProperty( nobj: GLUnurbsPtr ,  property:  GLenum): GLfloat;
    function nurbsCallback( nobj: GLUnurbsPtr , which: GLenum, cb: () => void ): void;
    function beginPolygon( tess: GLUtesselatorPtr  ): void;
    function nextContour( tess: GLUtesselatorPtr ,  type: GLenum): void;
    function endPolygon( tess: GLUtesselatorPtr ): void;
  }
  export default GLU;
}
