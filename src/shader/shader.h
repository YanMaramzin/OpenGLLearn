#pragma once

class Shader
{
public:
    Shader(const char *vertexPath, const char *fragmentPath);
    ~Shader() = default;
    void use() const;

    uint shaderProgram() const;
    void setBool(const std::string &name, bool value) const;
    void setInt(const std::string &name, int value) const;
    void setFloat(const std::string &name, float value) const;
private:
    uint program;
};
