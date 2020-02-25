#include <napi.h>


#define WIN32_LEAN_AND_MEAN             // Excluir itens raramente utilizados dos cabeçalhos do Windows
// Arquivos de Cabeçalho do Windows
#include <windows.h>
// Arquivos de Cabeçalho C RunTime
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>

// OpenGL Graphics Includes
#include <GL/gl.h>
#include <GL/glu.h>

#include <map>

#define JS_GLU___________________________TODO(name) puts("TODO: GLU."#name)
#define JS_GLU_CONSTANT(name) exports.Set(Napi::String::New(env, #name), Napi::Number::New(env, GLU_##name))
#define JS_GLU_SET_METHOD(name) exports.Set(Napi::String::New(env, #name), Napi::Function::New(env, name));
#define JS_ARGS(argc) \
if (info.Length() < argc) { \
  Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); \
  return env.Null(); \
}

#define JS_INT_ARG(pos, name) int32_t name = info[pos].As<Napi::Number>().Int32Value();
#define JS_LONG_ARG(pos, name) int64_t name = info[pos].As<Napi::Number>().Int64Value();
#define JS_UINT_ARG(pos, name) uint32_t name = info[pos].As<Napi::Number>().Uint32Value();
#define JS_STR_ARG(pos, name) std::string name = info[pos].As<Napi::String>().Utf8Value();
#define JS_DOUBLE_ARG(pos, name) double_t name = info[pos].As<Napi::Number>().DoubleValue();
#define JS_FLOAT_ARG(pos, name) float_t name = info[pos].As<Napi::Number>().FloatValue();
#define JS_PVOID_ARG(pos, name) void* name = (void*)info[pos].As<Napi::Number>().Int64Value();

#define JS_GLDOUBLE_ARG(pos, name) GLdouble name = info[pos].As<Napi::Number>().DoubleValue();
#define JS_GLFLOAT_ARG(pos, name) GLfloat name = info[pos].As<Napi::Number>().FloatValue();
#define JS_GLENUM_ARG(pos, name) GLenum name = info[pos].As<Napi::Number>().Uint32Value();
#define JS_GLUINT_ARG(pos, name) GLuint name = info[pos].As<Napi::Number>().Uint32Value();
#define JS_GLINT_ARG(pos, name) GLint name = info[pos].As<Napi::Number>().Int32Value();

#define JS_ARG_TYPE(pos, type)  if (!info[pos].Is##type()) { \
  Napi::TypeError::New(env, "Wrong arguments").ThrowAsJavaScriptException(); \
  return env.Null(); \
}

namespace glu {

// function errorString (errCode: GLenum): string;
Napi::Value errorString(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  JS_GLU___________________________TODO(errorString);
  return env.Undefined();
}
// function errorUnicodeString(errCode: GLenum): string;
Napi::Value errorUnicodeString(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  JS_GLU___________________________TODO(errorUnicodeString);
  return env.Undefined();
}
// function getString (name: GLenum): string;
Napi::Value getString(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  JS_GLU___________________________TODO(getString);
  return env.Undefined();
}
// function ortho2D(left: GLdouble ,right: GLdouble ,bottom: GLdouble ,top: GLdouble ): void;
Napi::Value ortho2D(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
	JS_ARGS(4);
	JS_ARG_TYPE(0, Number);
  JS_ARG_TYPE(1, Number);
  JS_ARG_TYPE(2, Number);
  JS_ARG_TYPE(3, Number);
  JS_DOUBLE_ARG(0, left);
  JS_DOUBLE_ARG(1, right);
  JS_DOUBLE_ARG(2, bottom);
  JS_DOUBLE_ARG(3, top);
  gluOrtho2D(left, right, bottom, top);
  return env.Undefined();
}
// function perspective(fovy: GLdouble ,aspect: GLdouble ,zNear: GLdouble ,zFar: GLdouble ): void;
Napi::Value perspective(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
	JS_ARGS(4);
	JS_ARG_TYPE(0, Number);
  JS_ARG_TYPE(1, Number);
  JS_ARG_TYPE(2, Number);
  JS_ARG_TYPE(3, Number);
  JS_DOUBLE_ARG(0, fovy);
  JS_DOUBLE_ARG(1, aspect);
  JS_DOUBLE_ARG(2, zNear);
  JS_DOUBLE_ARG(3, zFar);
  gluPerspective (fovy, aspect, zNear, zFar);
  return env.Undefined();
}
// function pickMatrix(x: GLdouble ,y: GLdouble ,width: GLdouble ,height: GLdouble , viewport:GLint[]): void;
Napi::Value pickMatrix(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  JS_GLU___________________________TODO(pickMatrix);
  return env.Undefined();
}
// function lookAt(eyex: GLdouble ,eyey: GLdouble ,eyez: GLdouble ,centerx: GLdouble ,centery: GLdouble ,centerz: GLdouble ,upx: GLdouble ,upy: GLdouble ,upz: GLdouble ): void;
Napi::Value lookAt(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
	JS_ARGS(9);
	JS_ARG_TYPE(0, Number);
  JS_ARG_TYPE(1, Number);
  JS_ARG_TYPE(2, Number);
  JS_ARG_TYPE(3, Number);
  JS_ARG_TYPE(4, Number);
  JS_ARG_TYPE(5, Number);
  JS_ARG_TYPE(6, Number);
  JS_ARG_TYPE(7, Number);
  JS_ARG_TYPE(8, Number);
  JS_GLDOUBLE_ARG(0, eyex);
  JS_GLDOUBLE_ARG(1, eyey);
  JS_GLDOUBLE_ARG(2, eyez);
  JS_GLDOUBLE_ARG(3, centerx);
  JS_GLDOUBLE_ARG(4, centery);
  JS_GLDOUBLE_ARG(5, centerz);
  JS_GLDOUBLE_ARG(6, upx);
  JS_GLDOUBLE_ARG(7, upy);
  JS_GLDOUBLE_ARG(8, upz);
  gluLookAt(eyex, eyey, eyez, centerx, centery, centerz, upx, upy, upz);
  return env.Undefined();
}
// function project( objx: GLdouble , objy: GLdouble , objz: GLdouble , modelMatrix: GLdouble[], projMatrix: GLdouble [], viewport: GLint[], winx: GLdouble , winy: GLdouble , winz: GLdouble ): number;
Napi::Value project(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  JS_GLU___________________________TODO(project);
  return env.Undefined();
}
// function unProject(winx: GLdouble ,winy: GLdouble ,winz: GLdouble , modelMatrix: GLdouble[], projMatrix: GLdouble [], viewport: GLint[], objx: GLdouble, objy: GLdouble, objz: GLdouble): number;
Napi::Value unProject(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  JS_GLU___________________________TODO(unProject);
  return env.Undefined();
}
// function scaleImage(format:  GLenum ,widthin: GLint ,heightin: GLint ,typein:  GLenum , datain: GLdouble[],widthout: GLint ,heightout: GLint ,typeout:  GLenum , dataout: GLdouble[]): number;
Napi::Value scaleImage(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  JS_GLU___________________________TODO(scaleImage);
  return env.Undefined();
}
// function build1DMipmaps(target:  GLenum ,components: GLint ,width: GLint ,format:  GLenum ,type:  GLenum , data: GLdouble[]): number;
Napi::Value build1DMipmaps(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  JS_GLU___________________________TODO(build1DMipmaps);
  return env.Undefined();
}
// function build2DMipmaps(target:  GLenum ,components: GLint ,width: GLint ,height: GLint ,format:  GLenum ,type:  GLenum , data: GLdouble[]): number;
Napi::Value build2DMipmaps(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  JS_GLU___________________________TODO(build2DMipmaps);
  return env.Undefined();
}
// function newQuadric(): GLUquadricPtr;
Napi::Value newQuadric(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  JS_GLU___________________________TODO(newQuadric);
  return env.Undefined();
}
// function deleteQuadric (state: GLUquadricPtr): void;
Napi::Value deleteQuadric(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  JS_GLU___________________________TODO(deleteQuadric);
  return env.Undefined();
}
// function quadricNormals(quadObject: GLUquadricPtr, normals: GLenum ): void;
Napi::Value quadricNormals(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  JS_GLU___________________________TODO(quadricNormals);
  return env.Undefined();
}
// function quadricTexture (quadObject: GLUquadricPtr, textureCoords: GLboolean ): void;
Napi::Value quadricTexture(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  JS_GLU___________________________TODO(quadricTexture);
  return env.Undefined();
}
// function quadricOrientation(quadObject: GLUquadricPtr ,orientation:  GLenum ): void;
Napi::Value quadricOrientation(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  JS_GLU___________________________TODO(quadricOrientation);
  return env.Undefined();
}
// function quadricDrawStyle(quadObject: GLUquadricPtr ,drawStyle:  GLenum ): void;
Napi::Value quadricDrawStyle(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  JS_GLU___________________________TODO(quadricDrawStyle);
  return env.Undefined();
}
// function cylinder(qobj: GLUquadricPtr ,baseRadius: GLdouble ,topRadius: GLdouble ,height: GLdouble ,slices: GLint ,stacks: GLint ): void;
Napi::Value cylinder(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  JS_GLU___________________________TODO(cylinder);
  return env.Undefined();
}
// function disk(qobj: GLUquadricPtr ,innerRadius: GLdouble ,outerRadius: GLdouble ,slices: GLint ,loops: GLint ): void;
Napi::Value disk(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  JS_GLU___________________________TODO(disk);
  return env.Undefined();
}
// function partialDisk(qobj: GLUquadricPtr ,innerRadius: GLdouble ,outerRadius: GLdouble ,slices: GLint ,loops: GLint ,startAngle: GLdouble ,sweepAngle: GLdouble ): void;
Napi::Value partialDisk(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  JS_GLU___________________________TODO(partialDisk);
  return env.Undefined();
}
// function sphere(qobj: GLUquadricPtr ,radius: GLdouble ,slices: GLint ,stacks: GLint ): void;
Napi::Value sphere(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  JS_GLU___________________________TODO(sphere);
  return env.Undefined();
}
// function quadricCallback(qobj: GLUquadricPtr ,  which:  GLenum , cb: () => void): void;
Napi::Value quadricCallback(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  JS_GLU___________________________TODO(quadricCallback);
  return env.Undefined();
}
// function newTess(): GLUtesselatorPtr;
Napi::Value newTess(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  JS_GLU___________________________TODO(newTess);
  return env.Undefined();
}
// function deleteTess( tess: GLUtesselatorPtr  ): void;
Napi::Value deleteTess(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  JS_GLU___________________________TODO(deleteTess);
  return env.Undefined();
}
// function tessBeginPolygon( tess: GLUtesselatorPtr , polygon_data:GLdouble[]): void;
Napi::Value tessBeginPolygon(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  JS_GLU___________________________TODO(tessBeginPolygon);
  return env.Undefined();
}
// function tessBeginContour( tess: GLUtesselatorPtr  ): void;
Napi::Value tessBeginContour(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  JS_GLU___________________________TODO(tessBeginContour);
  return env.Undefined();
}
// function tessVertex( tess: GLUtesselatorPtr ,coords: GLdouble[], data:GLdouble[] ): void;
Napi::Value tessVertex(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  JS_GLU___________________________TODO(tessVertex);
  return env.Undefined();
}
// function tessEndContour( tess: GLUtesselatorPtr  ): void;
Napi::Value tessEndContour(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  JS_GLU___________________________TODO(tessEndContour);
  return env.Undefined();
}
// function tessEndPolygon( tess: GLUtesselatorPtr  ): void;
Napi::Value tessEndPolygon(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  JS_GLU___________________________TODO(tessEndPolygon);
  return env.Undefined();
}
// function tessProperty( tess: GLUtesselatorPtr ,  which:  GLenum ,value: GLdouble  ): void;
Napi::Value tessProperty(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  JS_GLU___________________________TODO(tessProperty);
  return env.Undefined();
}
// function tessNormal( tess: GLUtesselatorPtr ,x: GLdouble ,y: GLdouble ,z: GLdouble  ): void;
Napi::Value tessNormal(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  JS_GLU___________________________TODO(tessNormal);
  return env.Undefined();
}
// function tessCallback( tess: GLUtesselatorPtr ,  which:  GLenum , cb: () => void): void;
Napi::Value tessCallback(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  JS_GLU___________________________TODO(tessCallback);
  return env.Undefined();
}
// function getTessProperty( tess: GLUtesselatorPtr ,  which:  GLenum): GLdouble
Napi::Value getTessProperty(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  JS_GLU___________________________TODO(getTessProperty);
  return env.Undefined();
}
// function newNurbsRenderer (): GLUnurbsPtr;
Napi::Value newNurbsRenderer(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  JS_GLU___________________________TODO(newNurbsRenderer);
  return env.Undefined();
}
// function deleteNurbsRenderer( nobj: GLUnurbsPtr ): void;
Napi::Value deleteNurbsRenderer(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  JS_GLU___________________________TODO(deleteNurbsRenderer);
  return env.Undefined();
}
// function beginSurface( nobj: GLUnurbsPtr ): void;
Napi::Value beginSurface(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  JS_GLU___________________________TODO(beginSurface);
  return env.Undefined();
}
// function beginCurve( nobj: GLUnurbsPtr ): void;
Napi::Value beginCurve(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  JS_GLU___________________________TODO(beginCurve);
  return env.Undefined();
}
// function endCurve( nobj: GLUnurbsPtr ): void;
Napi::Value endCurve(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  JS_GLU___________________________TODO(endCurve);
  return env.Undefined();
}
// function endSurface( nobj: GLUnurbsPtr ): void;
Napi::Value endSurface(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  JS_GLU___________________________TODO(endSurface);
  return env.Undefined();
}
// function beginTrim( nobj: GLUnurbsPtr ): void;
Napi::Value beginTrim(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  JS_GLU___________________________TODO(beginTrim);
  return env.Undefined();
}
// function endTrim( nobj: GLUnurbsPtr ): void;
Napi::Value endTrim(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  JS_GLU___________________________TODO(endTrim);
  return env.Undefined();
}
// function pwlCurve( nobj: GLUnurbsPtr ,count: GLint , array:GLfloat[],stride: GLint , type: GLenum ): void;
Napi::Value pwlCurve(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  JS_GLU___________________________TODO(pwlCurve);
  return env.Undefined();
}
// function nurbsCurve( nobj: GLUnurbsPtr ,nknots: GLint , knot: GLfloat,stride: GLint , ctlarray: GLfloat, order: GLint ,  type:  GLenum ): void;
Napi::Value nurbsCurve(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  JS_GLU___________________________TODO(nurbsCurve);
  return env.Undefined();
}
// function nurbsSurface( nobj: GLUnurbsPtr ,sknot_count: GLint , sknot: number,tknot_count: GLint ,   tknot: GLfloat,s_stride: GLint ,t_stride: GLint , ctlarray: GLfloat,sorder: GLint ,torder: GLint ,  type:  GLenum ): void;
Napi::Value nurbsSurface(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  JS_GLU___________________________TODO(nurbsSurface);
  return env.Undefined();
}
// function loadSamplingMatrices( nobj: GLUnurbsPtr , modelMatrix: GLfloat[], projMatrix: GLfloat[], viewport: GLint [] ): void;
Napi::Value loadSamplingMatrices(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  JS_GLU___________________________TODO(loadSamplingMatrices);
  return env.Undefined();
}
// function nurbsProperty( nobj: GLUnurbsPtr , property: GLenum , value: GLfloat ): void;
Napi::Value nurbsProperty(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  JS_GLU___________________________TODO(nurbsProperty);
  return env.Undefined();
}
// function getNurbsProperty( nobj: GLUnurbsPtr ,  property:  GLenum): GLfloat;
Napi::Value getNurbsProperty(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  JS_GLU___________________________TODO(getNurbsProperty);
  return env.Undefined();
}
// function nurbsCallback( nobj: GLUnurbsPtr , which: GLenum, cb: () => void ): void;
Napi::Value nurbsCallback(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  JS_GLU___________________________TODO(nurbsCallback);
  return env.Undefined();
}
// function beginPolygon( tess: GLUtesselatorPtr  ): void;
Napi::Value beginPolygon(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  JS_GLU___________________________TODO(beginPolygon);
  return env.Undefined();
}
// function nextContour( tess: GLUtesselatorPtr ,  type: GLenum): void;
Napi::Value nextContour(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  JS_GLU___________________________TODO(nextContour);
  return env.Undefined();
}
// function endPolygon( tess: GLUtesselatorPtr ): void;
Napi::Value endPolygon(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  JS_GLU___________________________TODO(endPolygon);
  return env.Undefined();
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {
  exports.Set(Napi::String::New(env, "perspective"), Napi::Function::New(env, perspective));



  /****  Generic constants ****/

  /* Version */
  JS_GLU_CONSTANT(VERSION_1_1);
  JS_GLU_CONSTANT(VERSION_1_2);

  /* Errors: (return value 0 = no error) */
  JS_GLU_CONSTANT(INVALID_ENUM);
  JS_GLU_CONSTANT(INVALID_VALUE);
  JS_GLU_CONSTANT(OUT_OF_MEMORY);
  JS_GLU_CONSTANT(INCOMPATIBLE_GL_VERSION);

  /* StringName */
  JS_GLU_CONSTANT(VERSION);
  JS_GLU_CONSTANT(EXTENSIONS);

  /* Boolean */
  JS_GLU_CONSTANT(TRUE);
  JS_GLU_CONSTANT(FALSE);


  /****  Quadric constants ****/

  /* QuadricNormal */
  JS_GLU_CONSTANT(SMOOTH);
  JS_GLU_CONSTANT(FLAT);
  JS_GLU_CONSTANT(NONE);

  /* QuadricDrawStyle */
  JS_GLU_CONSTANT(POINT);
  JS_GLU_CONSTANT(LINE);
  JS_GLU_CONSTANT(FILL);
  JS_GLU_CONSTANT(SILHOUETTE);

  /* QuadricOrientation */
  JS_GLU_CONSTANT(OUTSIDE);
  JS_GLU_CONSTANT(INSIDE);

  /* Callback types: */
  /* GLU_ERROR 100103 */


  /****  Tesselation constants  ****/

  JS_GLU_CONSTANT(TESS_MAX_COORD);

  /* TessProperty */
  JS_GLU_CONSTANT(TESS_WINDING_RULE);
  JS_GLU_CONSTANT(TESS_BOUNDARY_ONLY);
  JS_GLU_CONSTANT(TESS_TOLERANCE);

  /* TessWinding */
  JS_GLU_CONSTANT(TESS_WINDING_ODD);
  JS_GLU_CONSTANT(TESS_WINDING_NONZERO);
  JS_GLU_CONSTANT(TESS_WINDING_POSITIVE);
  JS_GLU_CONSTANT(TESS_WINDING_NEGATIVE);
  JS_GLU_CONSTANT(TESS_WINDING_ABS_GEQ_TWO);

  /* TessCallback */
  JS_GLU_CONSTANT(TESS_BEGIN);
  JS_GLU_CONSTANT(TESS_VERTEX);
  JS_GLU_CONSTANT(TESS_END);
  JS_GLU_CONSTANT(TESS_ERROR);
  JS_GLU_CONSTANT(TESS_EDGE_FLAG);
  JS_GLU_CONSTANT(TESS_COMBINE);
  JS_GLU_CONSTANT(TESS_BEGIN_DATA);
  JS_GLU_CONSTANT(TESS_VERTEX_DATA);
  JS_GLU_CONSTANT(TESS_END_DATA);
  JS_GLU_CONSTANT(TESS_ERROR_DATA);
  JS_GLU_CONSTANT(TESS_EDGE_FLAG_DATA);
  JS_GLU_CONSTANT(TESS_COMBINE_DATA);

  /* TessError */
  JS_GLU_CONSTANT(TESS_ERROR1);
  JS_GLU_CONSTANT(TESS_ERROR2);
  JS_GLU_CONSTANT(TESS_ERROR3);
  JS_GLU_CONSTANT(TESS_ERROR4);
  JS_GLU_CONSTANT(TESS_ERROR5);
  JS_GLU_CONSTANT(TESS_ERROR6);
  JS_GLU_CONSTANT(TESS_ERROR7);
  JS_GLU_CONSTANT(TESS_ERROR8);

  JS_GLU_CONSTANT(TESS_MISSING_BEGIN_POLYGON);
  JS_GLU_CONSTANT(TESS_MISSING_BEGIN_CONTOUR);
  JS_GLU_CONSTANT(TESS_MISSING_END_POLYGON);
  JS_GLU_CONSTANT(TESS_MISSING_END_CONTOUR);
  JS_GLU_CONSTANT(TESS_COORD_TOO_LARGE);
  JS_GLU_CONSTANT(TESS_NEED_COMBINE_CALLBACK);

  /****  NURBS constants   ****/

  /* NurbsProperty */
  JS_GLU_CONSTANT(AUTO_LOAD_MATRIX);
  JS_GLU_CONSTANT(CULLING);
  JS_GLU_CONSTANT(SAMPLING_TOLERANCE);
  JS_GLU_CONSTANT(DISPLAY_MODE);
  JS_GLU_CONSTANT(PARAMETRIC_TOLERANCE);
  JS_GLU_CONSTANT(SAMPLING_METHOD);
  JS_GLU_CONSTANT(U_STEP);
  JS_GLU_CONSTANT(V_STEP);

  /* NurbsSampling */
  JS_GLU_CONSTANT(PATH_LENGTH);
  JS_GLU_CONSTANT(PARAMETRIC_ERROR);
  JS_GLU_CONSTANT(DOMAIN_DISTANCE);


  /* NurbsTrim */
  JS_GLU_CONSTANT(MAP1_TRIM_2);
  JS_GLU_CONSTANT(MAP1_TRIM_3);

  /* NurbsDisplay */
  /* GLU_FILL  100012 */
  JS_GLU_CONSTANT(OUTLINE_POLYGON);
  JS_GLU_CONSTANT(OUTLINE_PATCH);

  /* NurbsCallback */
  /* GLU_ERROR 100103 */

  /* NurbsErrors */
  JS_GLU_CONSTANT(NURBS_ERROR1);
  JS_GLU_CONSTANT(NURBS_ERROR2);
  JS_GLU_CONSTANT(NURBS_ERROR3);
  JS_GLU_CONSTANT(NURBS_ERROR4);
  JS_GLU_CONSTANT(NURBS_ERROR5);
  JS_GLU_CONSTANT(NURBS_ERROR6);
  JS_GLU_CONSTANT(NURBS_ERROR7);
  JS_GLU_CONSTANT(NURBS_ERROR8);
  JS_GLU_CONSTANT(NURBS_ERROR9);
  JS_GLU_CONSTANT(NURBS_ERROR10);
  JS_GLU_CONSTANT(NURBS_ERROR11);
  JS_GLU_CONSTANT(NURBS_ERROR12);
  JS_GLU_CONSTANT(NURBS_ERROR13);
  JS_GLU_CONSTANT(NURBS_ERROR14);
  JS_GLU_CONSTANT(NURBS_ERROR15);
  JS_GLU_CONSTANT(NURBS_ERROR16);
  JS_GLU_CONSTANT(NURBS_ERROR17);
  JS_GLU_CONSTANT(NURBS_ERROR18);
  JS_GLU_CONSTANT(NURBS_ERROR19);
  JS_GLU_CONSTANT(NURBS_ERROR20);
  JS_GLU_CONSTANT(NURBS_ERROR21);
  JS_GLU_CONSTANT(NURBS_ERROR22);
  JS_GLU_CONSTANT(NURBS_ERROR23);
  JS_GLU_CONSTANT(NURBS_ERROR24);
  JS_GLU_CONSTANT(NURBS_ERROR25);
  JS_GLU_CONSTANT(NURBS_ERROR26);
  JS_GLU_CONSTANT(NURBS_ERROR27);
  JS_GLU_CONSTANT(NURBS_ERROR28);
  JS_GLU_CONSTANT(NURBS_ERROR29);
  JS_GLU_CONSTANT(NURBS_ERROR30);
  JS_GLU_CONSTANT(NURBS_ERROR31);
  JS_GLU_CONSTANT(NURBS_ERROR32);
  JS_GLU_CONSTANT(NURBS_ERROR33);
  JS_GLU_CONSTANT(NURBS_ERROR34);
  JS_GLU_CONSTANT(NURBS_ERROR35);
  JS_GLU_CONSTANT(NURBS_ERROR36);
  JS_GLU_CONSTANT(NURBS_ERROR37);

  /* Contours types -- obsolete! */
  JS_GLU_CONSTANT(CW);
  JS_GLU_CONSTANT(CCW);
  JS_GLU_CONSTANT(INTERIOR);
  JS_GLU_CONSTANT(EXTERIOR);
  JS_GLU_CONSTANT(UNKNOWN);

  /* Names without "TESS_" prefix */
  JS_GLU_CONSTANT(BEGIN);
  JS_GLU_CONSTANT(VERTEX);
  JS_GLU_CONSTANT(END);
  JS_GLU_CONSTANT(ERROR);
  JS_GLU_CONSTANT(EDGE_FLAG);

  JS_GLU_SET_METHOD(errorString);
  JS_GLU_SET_METHOD(errorUnicodeString);
  JS_GLU_SET_METHOD(getString);
  JS_GLU_SET_METHOD(ortho2D);
  JS_GLU_SET_METHOD(perspective);
  JS_GLU_SET_METHOD(pickMatrix);
  JS_GLU_SET_METHOD(lookAt);
  JS_GLU_SET_METHOD(project);
  JS_GLU_SET_METHOD(unProject);
  JS_GLU_SET_METHOD(scaleImage);
  JS_GLU_SET_METHOD(build1DMipmaps);
  JS_GLU_SET_METHOD(build2DMipmaps);
  JS_GLU_SET_METHOD(newQuadric);
  JS_GLU_SET_METHOD(deleteQuadric);
  JS_GLU_SET_METHOD(quadricNormals);
  JS_GLU_SET_METHOD(quadricTexture);
  JS_GLU_SET_METHOD(quadricOrientation);
  JS_GLU_SET_METHOD(quadricDrawStyle);
  JS_GLU_SET_METHOD(cylinder);
  JS_GLU_SET_METHOD(disk);
  JS_GLU_SET_METHOD(partialDisk);
  JS_GLU_SET_METHOD(sphere);
  JS_GLU_SET_METHOD(quadricCallback);
  JS_GLU_SET_METHOD(newTess);
  JS_GLU_SET_METHOD(deleteTess);
  JS_GLU_SET_METHOD(tessBeginPolygon);
  JS_GLU_SET_METHOD(tessBeginContour);
  JS_GLU_SET_METHOD(tessVertex);
  JS_GLU_SET_METHOD(tessEndContour);
  JS_GLU_SET_METHOD(tessEndPolygon);
  JS_GLU_SET_METHOD(tessProperty);
  JS_GLU_SET_METHOD(tessNormal);
  JS_GLU_SET_METHOD(tessCallback);
  JS_GLU_SET_METHOD(getTessProperty);
  JS_GLU_SET_METHOD(newNurbsRenderer);
  JS_GLU_SET_METHOD(deleteNurbsRenderer);
  JS_GLU_SET_METHOD(beginSurface);
  JS_GLU_SET_METHOD(beginCurve);
  JS_GLU_SET_METHOD(endCurve);
  JS_GLU_SET_METHOD(endSurface);
  JS_GLU_SET_METHOD(beginTrim);
  JS_GLU_SET_METHOD(endTrim);
  JS_GLU_SET_METHOD(pwlCurve);
  JS_GLU_SET_METHOD(nurbsCurve);
  JS_GLU_SET_METHOD(nurbsSurface);
  JS_GLU_SET_METHOD(loadSamplingMatrices);
  JS_GLU_SET_METHOD(nurbsProperty);
  JS_GLU_SET_METHOD(getNurbsProperty);
  JS_GLU_SET_METHOD(nurbsCallback);
  JS_GLU_SET_METHOD(beginPolygon);
  JS_GLU_SET_METHOD(nextContour);
  JS_GLU_SET_METHOD(endPolygon);

  return exports;
}

NODE_API_MODULE(hello, Init)

}  // namespace glu
