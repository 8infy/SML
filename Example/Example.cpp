#include <iostream>

#include <sml/sml.h>

int main()
{
    /*----2 component vectors----*/

    // Vector of boolean values
    sml::bvec2 bool_vec2(true, false);

    // Vector of integers
    sml::ivec2 int_vec2(-1, -2);

    // Vector of unsigned integers
    sml::uvec2 unsigned_vec2(10, 20);

    // Vector of floating points
    sml::vec2  float_vec2(2.5f, 2.0f);

    // Vector of double precision floating points
    sml::dvec2 double_vec2(5.0, 5.0);

    // Normalize the vector
    sml::normalize(double_vec2);

    // Magnitude of our vector
    float magn = sml::magnitude(int_vec2);

    /*----3 component vectors----*/

    // Vector of boolean values (all set to true)
    sml::bvec3 bool_vec3(true);

    // Vector of integers (x and y are copied from int_vec2).
    sml::ivec3 int_vec3(int_vec2, 30);

    // Vector of unsigned integers
    sml::uvec3 unsigned_vec3(10, 20, 30);

    // Vector of floating points
    sml::vec3  float_vec3(2.5f, 2.0f, 1.5f);

    // Vector of double precision floating points
    sml::dvec3 double_vec3(5.0, 5.0, 5.0);

    // Cross product of the two vectors
    sml::vec3 cross_vec = sml::cross(double_vec3, float_vec3);

    // Finding the dot product of the two vectors
    float dot_pr = sml::dot(float_vec3, double_vec3);

    /*----4 component vectors----*/

    // Vector of boolean values (x and y are copied from bool_vec2)
    sml::bvec4 bool_vec4(bool_vec2, false, false);

    // Vector of integers (x, y and z are copied from int_vec3).
    sml::ivec4 int_vec4(int_vec3, 40);

    // Vector of unsigned integers (x,y and z are copied from unsigned_vec3, w set to 1)
    sml::uvec4 unsigned_vec4(unsigned_vec3);

    // Vector of floating points (x and y are copied from float_vec2, z set to 0, w set to 1)
    sml::vec4  float_vec4(float_vec2);

    // Vector of double precision floating points
    sml::dvec4 double_vec4(5.0, 5.0, 5.0, 5.0);

    float x = float_vec4.x; // accessing element x
    float y = float_vec4.y; // accessing element y
    float z = float_vec4.z; // accessing element z
    float w = float_vec4.w; // accessing element w

    float r = float_vec4.r; // same as x
    float g = float_vec4.g; // same as y
    float b = float_vec4.b; // same as z
    float a = float_vec4.a; // same as w

    /*------4x4 matricies------*/
    
    // Standard floating point matrix
    // Diagonal elements are set to 1.0f
    sml::mat4 floating_point_matrix(1.0f);

    // Indentity matrix
    sml::mat4 iden = sml::mat4::identity();
    
    // invert the matrix
    iden.invert();

    // Constructing an orthographic matrix
    sml::mat4 ortho = sml::mat4::orthographic(-1.0f, 1.0f, -1.0f, 1.0f, 0.1f, 1.0f);

    // Same as above
    sml::mat4 orth2 = sml::orthographic(-1.0f, 1.0f, -1.0f, 1.0f, 0.1f, 1.0f);

    // Constructing a perspective matrix
    sml::mat4 persp = sml::mat4::perspective(90, 16.0f / 9.0f, 0.1f, 1.0f);

    // Same as above
    sml::mat4 persp2 = sml::perspective(90, 16.0f / 9.0f, 0.1f, 1.0f);

    // Constructing a lookAt matrix (implicit and explicit constructors)
    sml::mat4 lookat = sml::lookAt(sml::vec3(1.0f, 1.0f, 1.0f), { 0.0f, 1.0f, 0.0f }, { 0.0f, 1.0f, 1.0f });

    // Accessing matrix elements
    float first_column_third_element = lookat[0][2];

    // Getting access to the buffer
    float* matrix_data = lookat.data();

    // Same as above
    float* matrix_data2 = &lookat[0][0];

    // Multiplying to matricies
    sml::mat4 new_matrix = lookat * persp;

    // Short-hand multiplication
    new_matrix *= lookat;

    // Scale the matrix
    sml::mat4 scaled_matrix = sml::scale(iden, { 25, 25, 25 });

    // Rotate the matrix 90 DEGREES along the X axis
    sml::mat4 rotated_matrix = sml::rotate(scaled_matrix, 90.0f, { 1, 0, 0 });

    // Same as above but using member functions
    scaled_matrix.scale({ 25, 25, 25 });
    scaled_matrix.rotate(90.0f, { 1, 0, 0 });

    // Translate the matrix
    scaled_matrix.translate({ 25.0f, 25.0f, 0.0f });

    // Same as above
    sml::mat4 translated_matrix = sml::translate(scaled_matrix, { 25.0f, 25.0f, 0.0f });

    // Double 4x4 matrix, requires GL >= 4.0
    sml::dmat4 double_precision_matrix(1.0f);

    // Rotate the matrix
    sml::dmat4 rotated_double_matrix = sml::rotate(double_precision_matrix, 25.0f, { 25.0, 25.0, 25.0 });

    std::cin.get();
    return 0;
}