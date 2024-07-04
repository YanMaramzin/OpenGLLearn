#pragma once

class Shader
{
public:
    Shader(const char *vertexPath, const char *fragmentPath);
    ~Shader() = default;
    void use() const;
private:
    unsigned int program;
};
