#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include "shader.h"

#include <GL/glew.h>

#include "../logger/logger.h"

Shader::Shader(const char *vertexPath, const char *fragmentPath)
{
    std::string vertexCode;
    std::string fragmentCode;
    std::ifstream vShaderFile;
    std::ifstream fShaderFile;
    vShaderFile.exceptions(std::ifstream::badbit);
    fShaderFile.exceptions(std::ifstream::badbit);
    try {
        vShaderFile.open(vertexPath);
        fShaderFile.open(fragmentPath);
        std::stringstream vShaderStream;
        std::stringstream fShaderStream;

        vShaderStream << vShaderFile.rdbuf();
        fShaderStream << fShaderFile.rdbuf();

        vShaderFile.close();
        fShaderFile.close();

        vertexCode = vShaderStream.str();
        fragmentCode = fShaderStream.str();

    } catch (std::ifstream::failure e) {
        Logger::error("ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ");
    }

    const char *vShaderCode = vertexCode.c_str();
    const char *fShaderCode = fragmentCode.c_str();

    uint vertex;
    uint fragment;
    int success;

    // Вершинный шейдер
    vertex = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex, 1, &vShaderCode, nullptr);
    glCompileShader(vertex);

    glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);

    if (!success) {
        char infoLog[512];
        glGetShaderInfoLog(vertex, 512, nullptr, infoLog);
        Logger::error("SHADER::VERTEX::COMPILATION_FAILED" + std::string(infoLog));
    }

    // Вершинный шейдер
    fragment = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment, 1, &fShaderCode, nullptr);
    glCompileShader(fragment);

    glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);

    if (!success) {
        char infoLog[512];
        glGetShaderInfoLog(fragment, 512, nullptr, infoLog);
        Logger::error("SHADER::FRAGMENT::COMPILATION_FAILED" + std::string(infoLog));
    }

    program = glCreateProgram();
    glAttachShader(program, vertex);
    glAttachShader(program, fragment);
    glLinkProgram(program);
    glGetProgramiv(program, GL_LINK_STATUS, &success);

    if (!success) {
        char infoLog[512];
        glGetProgramInfoLog(program, 512, nullptr, infoLog);
        Logger::error("SHADER::PROGRAM::LINKING_FAILED" + std::string(infoLog));
    }

    glDeleteShader(vertex);
    glDeleteShader(fragment);
}

void Shader::use() const
{
    glUseProgram(program);
}

uint Shader::shaderProgram() const
{
    return program;
}

void Shader::setBool(const std::string &name, const bool value) const
{
    glUniform1i(glGetUniformLocation(program, name.c_str()), value);
}

void Shader::setInt(const std::string &name, const int value) const
{
    glUniform1i(glGetUniformLocation(program, name.c_str()), value);
}

void Shader::setFloat(const std::string &name, const float value) const
{
    glUniform1f(glGetUniformLocation(program, name.c_str()), value);
}

