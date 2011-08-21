#ifndef __OGL_HPP__
#define __OGL_HPP__

#include "sys/platform.hpp"
#include "sys/filename.hpp"

#include "GL/gl3.h"
#include "GL/glext.h"
#include <string>
#include <vector>

namespace pf
{
  /*! We load all OGL functions explicitly */
  struct OGL {
    OGL(void);
    virtual ~OGL(void);

    /*! OpenGL 1.0 functions */
    PFNGLCULLFACEPROC CullFace;
    PFNGLFRONTFACEPROC FrontFace;
    PFNGLHINTPROC Hint;
    PFNGLLINEWIDTHPROC LineWidth;
    PFNGLPOINTSIZEPROC PointSize;
    PFNGLPOLYGONMODEPROC PolygonMode;
    PFNGLSCISSORPROC Scissor;
    PFNGLTEXPARAMETERFPROC TexParameterf;
    PFNGLTEXPARAMETERFVPROC TexParameterfv;
    PFNGLTEXPARAMETERIPROC TexParameteri;
    PFNGLTEXPARAMETERIVPROC TexParameteriv;
    PFNGLTEXIMAGE1DPROC TexImage1D;
    PFNGLTEXIMAGE2DPROC TexImage2D;
    PFNGLDRAWBUFFERPROC DrawBuffer;
    PFNGLCLEARPROC Clear;
    PFNGLCLEARCOLORPROC ClearColor;
    PFNGLCLEARSTENCILPROC ClearStencil;
    PFNGLCLEARDEPTHPROC ClearDepth;
    PFNGLSTENCILMASKPROC StencilMask;
    PFNGLCOLORMASKPROC ColorMask;
    PFNGLDEPTHMASKPROC DepthMask;
    PFNGLDISABLEPROC Disable;
    PFNGLENABLEPROC Enable;
    PFNGLFINISHPROC Finish;
    PFNGLFLUSHPROC Flush;
    PFNGLBLENDFUNCPROC BlendFunc;
    PFNGLLOGICOPPROC LogicOp;
    PFNGLSTENCILFUNCPROC StencilFunc;
    PFNGLSTENCILOPPROC StencilOp;
    PFNGLDEPTHFUNCPROC DepthFunc;
    PFNGLPIXELSTOREFPROC PixelStoref;
    PFNGLPIXELSTOREIPROC PixelStorei;
    PFNGLREADBUFFERPROC ReadBuffer;
    PFNGLREADPIXELSPROC ReadPixels;
    PFNGLGETBOOLEANVPROC GetBooleanv;
    PFNGLGETDOUBLEVPROC GetDoublev;
    PFNGLGETERRORPROC GetError;
    PFNGLGETFLOATVPROC GetFloatv;
    PFNGLGETINTEGERVPROC GetIntegerv;
    PFNGLGETSTRINGPROC GetString;
    PFNGLGETTEXIMAGEPROC GetTexImage;
    PFNGLGETTEXPARAMETERFVPROC GetTexParameterfv;
    PFNGLGETTEXPARAMETERIVPROC GetTexParameteriv;
    PFNGLGETTEXLEVELPARAMETERFVPROC GetTexLevelParameterfv;
    PFNGLGETTEXLEVELPARAMETERIVPROC GetTexLevelParameteriv;
    PFNGLISENABLEDPROC IsEnabled;
    PFNGLDEPTHRANGEPROC DepthRange;
    PFNGLVIEWPORTPROC Viewport;

    /*! OpenGL 1.1 functions */
    PFNGLDRAWARRAYSPROC DrawArrays;
    PFNGLDRAWELEMENTSPROC DrawElements;
    PFNGLGETPOINTERVPROC GetPointerv;
    PFNGLPOLYGONOFFSETPROC PolygonOffset;
    PFNGLCOPYTEXIMAGE1DPROC CopyTexImage1D;
    PFNGLCOPYTEXIMAGE2DPROC CopyTexImage2D;
    PFNGLCOPYTEXSUBIMAGE1DPROC CopyTexSubImage1D;
    PFNGLCOPYTEXSUBIMAGE2DPROC CopyTexSubImage2D;
    PFNGLTEXSUBIMAGE1DPROC TexSubImage1D ;
    PFNGLTEXSUBIMAGE2DPROC TexSubImage2D ;
    PFNGLBINDTEXTUREPROC BindTexture;
    PFNGLDELETETEXTURESPROC DeleteTextures;
    PFNGLGENTEXTURESPROC GenTextures;
    PFNGLISTEXTUREPROC IsTexture;

    /*! OpenGL 1.2 functions */
    PFNGLBLENDCOLORPROC BlendColor;
    PFNGLBLENDEQUATIONPROC BlendEquation;
    PFNGLDRAWRANGEELEMENTSPROC DrawRangeElements;
    PFNGLTEXIMAGE3DPROC TexImage3D;
    PFNGLTEXSUBIMAGE3DPROC TexSubImage3D;
    PFNGLCOPYTEXSUBIMAGE3DPROC CopyTexSubImage3D;

    /*! OpenGL 1.3 functions */
    PFNGLACTIVETEXTUREPROC ActiveTexture;
    PFNGLSAMPLECOVERAGEPROC SampleCoverage;
    PFNGLCOMPRESSEDTEXIMAGE3DPROC CompressedTexImage3D;
    PFNGLCOMPRESSEDTEXIMAGE2DPROC CompressedTexImage2D;
    PFNGLCOMPRESSEDTEXIMAGE1DPROC CompressedTexImage1D;
    PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC CompressedTexSubImage3D;
    PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC CompressedTexSubImage2D;
    PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC CompressedTexSubImage1D;
    PFNGLGETCOMPRESSEDTEXIMAGEPROC GetCompressedTexImage;

    /*! OpenGL 1.5 functions */
    PFNGLGENQUERIESPROC GenQueries;
    PFNGLDELETEQUERIESPROC DeleteQueries;
    PFNGLISQUERYPROC IsQuery;
    PFNGLBEGINQUERYPROC BeginQuery;
    PFNGLENDQUERYPROC EndQuery;
    PFNGLGETQUERYIVPROC GetQueryiv;
    PFNGLGETQUERYOBJECTIVPROC GetQueryObjectiv;
    PFNGLGETQUERYOBJECTUIVPROC GetQueryObjectuiv;
    PFNGLBINDBUFFERPROC BindBuffer;
    PFNGLDELETEBUFFERSPROC DeleteBuffers;
    PFNGLGENBUFFERSPROC GenBuffers;
    PFNGLISBUFFERPROC IsBuffer;
    PFNGLBUFFERDATAPROC BufferData;
    PFNGLBUFFERSUBDATAPROC BufferSubData;
    PFNGLGETBUFFERSUBDATAPROC GetBufferSubData;
    PFNGLMAPBUFFERPROC MapBuffer;
    PFNGLUNMAPBUFFERPROC UnmapBuffer;
    PFNGLGETBUFFERPARAMETERIVPROC GetBufferParameteriv;
    PFNGLGETBUFFERPOINTERVPROC GetBufferPointerv;

    /*! OpenGL 2.0 functions */
    PFNGLBLENDEQUATIONSEPARATEPROC BlendEquationSeparate;
    PFNGLDRAWBUFFERSPROC DrawBuffers;
    PFNGLSTENCILOPSEPARATEPROC StencilOpSeparate;
    PFNGLSTENCILFUNCSEPARATEPROC StencilFuncSeparate;
    PFNGLSTENCILMASKSEPARATEPROC StencilMaskSeparate;
    PFNGLATTACHSHADERPROC AttachShader;
    PFNGLBINDATTRIBLOCATIONPROC BindAttribLocation;
    PFNGLCOMPILESHADERPROC CompileShader;
    PFNGLCREATEPROGRAMPROC CreateProgram;
    PFNGLCREATESHADERPROC CreateShader;
    PFNGLDELETEPROGRAMPROC DeleteProgram;
    PFNGLDELETESHADERPROC DeleteShader;
    PFNGLDETACHSHADERPROC DetachShader;
    PFNGLDISABLEVERTEXATTRIBARRAYPROC DisableVertexAttribArray;
    PFNGLENABLEVERTEXATTRIBARRAYPROC EnableVertexAttribArray;
    PFNGLGETACTIVEATTRIBPROC GetActiveAttrib;
    PFNGLGETACTIVEUNIFORMPROC GetActiveUniform;
    PFNGLGETATTACHEDSHADERSPROC GetAttachedShaders;
    PFNGLGETATTRIBLOCATIONPROC GetAttribLocation;
    PFNGLGETPROGRAMIVPROC GetProgramiv;
    PFNGLGETPROGRAMINFOLOGPROC GetProgramInfoLog;
    PFNGLGETSHADERIVPROC GetShaderiv;
    PFNGLGETSHADERINFOLOGPROC GetShaderInfoLog;
    PFNGLGETSHADERSOURCEPROC GetShaderSource;
    PFNGLGETUNIFORMLOCATIONPROC GetUniformLocation;
    PFNGLGETUNIFORMFVPROC GetUniformfv;
    PFNGLGETUNIFORMIVPROC GetUniformiv;
    PFNGLGETVERTEXATTRIBDVPROC GetVertexAttribdv;
    PFNGLGETVERTEXATTRIBFVPROC GetVertexAttribfv;
    PFNGLGETVERTEXATTRIBIVPROC GetVertexAttribiv;
    PFNGLGETVERTEXATTRIBPOINTERVPROC GetVertexAttribPointerv;
    PFNGLISPROGRAMPROC IsProgram;
    PFNGLISSHADERPROC IsShader;
    PFNGLLINKPROGRAMPROC LinkProgram;
    PFNGLSHADERSOURCEPROC ShaderSource;
    PFNGLUSEPROGRAMPROC UseProgram;
    PFNGLUNIFORM1FPROC Uniform1f;
    PFNGLUNIFORM2FPROC Uniform2f;
    PFNGLUNIFORM3FPROC Uniform3f;
    PFNGLUNIFORM4FPROC Uniform4f;
    PFNGLUNIFORM1IPROC Uniform1i;
    PFNGLUNIFORM2IPROC Uniform2i;
    PFNGLUNIFORM3IPROC Uniform3i;
    PFNGLUNIFORM4IPROC Uniform4i;
    PFNGLUNIFORM1FVPROC Uniform1fv;
    PFNGLUNIFORM2FVPROC Uniform2fv;
    PFNGLUNIFORM3FVPROC Uniform3fv;
    PFNGLUNIFORM4FVPROC Uniform4fv;
    PFNGLUNIFORM1IVPROC Uniform1iv;
    PFNGLUNIFORM2IVPROC Uniform2iv;
    PFNGLUNIFORM3IVPROC Uniform3iv;
    PFNGLUNIFORM4IVPROC Uniform4iv;
    PFNGLUNIFORMMATRIX2FVPROC UniformMatrix2fv;
    PFNGLUNIFORMMATRIX3FVPROC UniformMatrix3fv;
    PFNGLUNIFORMMATRIX4FVPROC UniformMatrix4fv;
    PFNGLVALIDATEPROGRAMPROC ValidateProgram;
    PFNGLVERTEXATTRIB1DPROC VertexAttrib1d;
    PFNGLVERTEXATTRIB1DVPROC VertexAttrib1dv;
    PFNGLVERTEXATTRIB1FPROC VertexAttrib1f;
    PFNGLVERTEXATTRIB1FVPROC VertexAttrib1fv;
    PFNGLVERTEXATTRIB1SPROC VertexAttrib1s;
    PFNGLVERTEXATTRIB1SVPROC VertexAttrib1sv;
    PFNGLVERTEXATTRIB2DPROC VertexAttrib2d;
    PFNGLVERTEXATTRIB2DVPROC VertexAttrib2dv;
    PFNGLVERTEXATTRIB2FPROC VertexAttrib2f;
    PFNGLVERTEXATTRIB2FVPROC VertexAttrib2fv;
    PFNGLVERTEXATTRIB2SPROC VertexAttrib2s;
    PFNGLVERTEXATTRIB2SVPROC VertexAttrib2sv;
    PFNGLVERTEXATTRIB3DPROC VertexAttrib3d;
    PFNGLVERTEXATTRIB3DVPROC VertexAttrib3dv;
    PFNGLVERTEXATTRIB3FPROC VertexAttrib3f;
    PFNGLVERTEXATTRIB3FVPROC VertexAttrib3fv;
    PFNGLVERTEXATTRIB3SPROC VertexAttrib3s;
    PFNGLVERTEXATTRIB3SVPROC VertexAttrib3sv;
    PFNGLVERTEXATTRIB4NBVPROC VertexAttrib4Nbv;
    PFNGLVERTEXATTRIB4NIVPROC VertexAttrib4Niv;
    PFNGLVERTEXATTRIB4NSVPROC VertexAttrib4Nsv;
    PFNGLVERTEXATTRIB4NUBPROC VertexAttrib4Nub;
    PFNGLVERTEXATTRIB4NUBVPROC VertexAttrib4Nubv;
    PFNGLVERTEXATTRIB4NUIVPROC VertexAttrib4Nuiv;
    PFNGLVERTEXATTRIB4NUSVPROC VertexAttrib4Nusv;
    PFNGLVERTEXATTRIB4BVPROC VertexAttrib4bv;
    PFNGLVERTEXATTRIB4DPROC VertexAttrib4d;
    PFNGLVERTEXATTRIB4DVPROC VertexAttrib4dv;
    PFNGLVERTEXATTRIB4FPROC VertexAttrib4f;
    PFNGLVERTEXATTRIB4FVPROC VertexAttrib4fv;
    PFNGLVERTEXATTRIB4IVPROC VertexAttrib4iv;
    PFNGLVERTEXATTRIB4SPROC VertexAttrib4s;
    PFNGLVERTEXATTRIB4SVPROC VertexAttrib4sv;
    PFNGLVERTEXATTRIB4UBVPROC VertexAttrib4ubv;
    PFNGLVERTEXATTRIB4UIVPROC VertexAttrib4uiv;
    PFNGLVERTEXATTRIB4USVPROC VertexAttrib4usv;
    PFNGLVERTEXATTRIBPOINTERPROC VertexAttribPointer;

    /*! OpenGL 3.0 functions */
    PFNGLBINDBUFFERBASEPROC BindBufferBase;
    PFNGLBINDFRAGDATALOCATIONPROC BindFragDataLocation;
    PFNGLGENERATEMIPMAPPROC GenerateMipmap;
    PFNGLDELETEVERTEXARRAYSPROC DeleteVertexArrays;
    PFNGLGENVERTEXARRAYSPROC GenVertexArrays;
    PFNGLBINDVERTEXARRAYPROC BindVertexArray;
    PFNGLGENFRAMEBUFFERSPROC GenFramebuffers;
    PFNGLBINDFRAMEBUFFERPROC BindFramebuffer;
    PFNGLFRAMEBUFFERTEXTURELAYERPROC FramebufferTextureLayer;
    PFNGLFRAMEBUFFERTEXTURE2DPROC FramebufferTexture2D;
    PFNGLCHECKFRAMEBUFFERSTATUSPROC CheckFramebufferStatus;
    PFNGLDELETEFRAMEBUFFERSPROC DeleteFramebuffers;
    PFNGLMAPBUFFERRANGEPROC MapBufferRange;
    PFNGLFLUSHMAPPEDBUFFERRANGEPROC FlushMappedBufferRange;
    PFNGLGENRENDERBUFFERSPROC GenRenderbuffers;
    PFNGLBINDRENDERBUFFERPROC BindRenderbuffer;
    PFNGLRENDERBUFFERSTORAGEPROC RenderbufferStorage;
    PFNGLFRAMEBUFFERRENDERBUFFERPROC FramebufferRenderbuffer;
    PFNGLBLITFRAMEBUFFERPROC BlitFramebuffer;
    PFNGLDELETERENDERBUFFERSPROC DeleteRenderbuffers;
    PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC RenderbufferStorageMultisample;
    PFNGLCOLORMASKIPROC ColorMaski;
    PFNGLGETBOOLEANI_VPROC GetBooleani_v;
    PFNGLGETINTEGERI_VPROC GetIntegeri_v;
    PFNGLENABLEIPROC Enablei;
    PFNGLDISABLEIPROC Disablei;

    /*! OpenGL 3.1 functions */
    PFNGLBINDBUFFERRANGEPROC BindBufferRange;
    PFNGLDRAWARRAYSINSTANCEDPROC DrawArraysInstanced;
    PFNGLDRAWELEMENTSINSTANCEDPROC DrawElementsInstanced;
    PFNGLTEXBUFFERPROC TexBuffer;
    PFNGLPRIMITIVERESTARTINDEXPROC PrimitiveRestartIndex;
    PFNGLGETUNIFORMINDICESPROC GetUniformIndices;
    PFNGLGETACTIVEUNIFORMSIVPROC GetActiveUniformsiv;
    PFNGLGETACTIVEUNIFORMNAMEPROC GetActiveUniformName;
    PFNGLGETUNIFORMBLOCKINDEXPROC GetUniformBlockIndex;
    PFNGLGETACTIVEUNIFORMBLOCKIVPROC GetActiveUniformBlockiv;
    PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC GetActiveUniformBlockName;
    PFNGLUNIFORMBLOCKBINDINGPROC UniformBlockBinding;

    /*! OpenGL 3.2 functions */
    PFNGLGETINTEGER64I_VPROC GetInteger64i_v;
    PFNGLGETBUFFERPARAMETERI64VPROC GetBufferParameteri64v;
    PFNGLFRAMEBUFFERTEXTUREPROC FramebufferTexture;

    /*! OpenGL 3.3 functions */
    PFNGLGENSAMPLERSPROC GenSamplers;
    PFNGLDELETESAMPLERSPROC DeleteSamplers;
    PFNGLISSAMPLERPROC IsSampler;
    PFNGLBINDSAMPLERPROC BindSampler;
    PFNGLSAMPLERPARAMETERIPROC SamplerParameteri;
    PFNGLSAMPLERPARAMETERIVPROC SamplerParameteriv;
    PFNGLSAMPLERPARAMETERFPROC SamplerParameterf;
    PFNGLSAMPLERPARAMETERFVPROC SamplerParameterfv;
    PFNGLSAMPLERPARAMETERIIVPROC SamplerParameterIiv;
    PFNGLSAMPLERPARAMETERIUIVPROC SamplerParameterIuiv;
    PFNGLGETSAMPLERPARAMETERIVPROC GetSamplerParameteriv;
    PFNGLGETSAMPLERPARAMETERIIVPROC GetSamplerParameterIiv;
    PFNGLGETSAMPLERPARAMETERFVPROC GetSamplerParameterfv;
    PFNGLGETSAMPLERPARAMETERIUIVPROC GetSamplerParameterIuiv;
    PFNGLVERTEXATTRIBDIVISORPROC VertexAttribDivisor;

    /*! Driver dependent constants */
    int32_t maxColorAttachmentNum;
    int32_t maxTextureSize;
    int32_t maxTextureUnit;

    /*! Check that no error happened */
    bool checkError(const char *title = NULL) const;
    /*! Check that the frame buffer is properly setup */
    bool checkFramebuffer(GLuint frameBufferName) const;
    /*! Validate the program */
    bool validateProgram(GLuint programName) const;
    /*! Check that the program is properly created */
    bool checkProgram(GLuint programName) const;
    /*! Create a shader from the path of the source */
    GLuint createShader(GLenum type, const FileName &path) const;
    /*! Create a shader from the source */
    GLuint createShader(GLenum type, const std::string &source) const;
  };

  /*! One instance is enough */
  extern OGL *ogl;

/*! Convenient way to catch all GL related errors. User defines the name of the
 *  structure which contains all OGL functions with name OGL_NAME
 */
#ifndef NDEBUG
  #define R_CALL(NAME, ...)                                                   \
    do {                                                                      \
      OGL_NAME->NAME(__VA_ARGS__);                                            \
      FATAL_IF (OGL_NAME->checkError(__FUNCTION__) == false, #NAME " failed");\
    } while (0)
  #define R_CALLR(RET, NAME, ...)                                             \
    do {                                                                      \
      RET = OGL_NAME->NAME(__VA_ARGS__);                                      \
      FATAL_IF (OGL_NAME->checkError(__FUNCTION__) == false, #NAME " failed");\
    } while (0)
#else
  #define R_CALL(NAME, ...) do { OGL_NAME->NAME(__VA_ARGS__); } while (0)
  #define R_CALLR(RET, NAME, ...) do { RET = OGL_NAME->NAME(__VA_ARGS__); } while (0)
#endif /* NDEBUG */

}

#endif /* __OGL_HPP__ */

