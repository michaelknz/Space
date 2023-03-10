#pragma once
#include <Glad/glad.h>
#include <string>
#include <vector>
#include "Math/MathStructs.h"

class Shader {
public:
	Shader(const std::string& shader_name, int shader_col);
	virtual ~Shader();
	void Bind();
	void Unbind();
	void Compile();
	void SendMatrix4x4f(const Matrix4x4f& mat, const std::string& un_name);
	void Send1i(int val, const std::string& un_name);
protected:
	void MakeShader(const std::string& file_name, GLuint type);
private:
	std::string ReadShader(const std::string& filename);
	void CompileShader(const std::string& text, GLuint type);
	void DetachShaders();
	virtual void MakeProg(const std::string& shader_name);
	void AttachShaders(int shader_col);
	GLuint prog;
	std::vector<GLuint> shaders;
	std::string shader_name;
};