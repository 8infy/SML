# SML
## A header-only math library intended for use with any rendering APIs out there. Uses GLSL syntax & column-major.
---
## Please note:
- SML functions always expect degrees for angles/fov/anything and NOT radians!
- It is recommended to include sml.h instead of including headers separately because you gain additional functionality & less cluttered translation unit.
- Right now SML only supports floating point matricies & vectors. Support for other types might get added in the future.
---
## Utils (functions defined inside utils.h):
- `float to_radians(float degrees)` -> converts degrees into radians.
- `float to_degrees(float radians)` -> converts radians into degrees.
---
## Vectors:
- Elements can be accessed with subscript(`[]`) operator, as well as `.elements`, or `.x`, `.y`, `.z`, `.w` and `.r`, `.g`, `.b`, `.a` if you're working with colors.
- All vectors have the neccessary operator overloads such as `+`, `-`, `/`, `*`. Their shorthand counterparts are also available, e.g `+=`.
- Dot/cross product member function + sml.h functions.
- Vectors can be normalized with `normalize(const vec& vec)` defined in sml.h.
- If you want to access the elements directly/get the pointer you can call `.data()` or use `&vec[0]`.
## Currently supported vectors: 
- `vec2` -> 2 component vector.
- `vec3` -> 3 component vector.
- `vec4` -> 4 component vector.
---
## Matrix:
-  Elements can be accessed with `myMatrix[column][element]`, as well as `.elements[row + column * 4]`.
## Mat4 constructors:
- `mat4()` -> all elements set to 0.
- `mat4::identity()` -> returns and identity matrix (all diagonal elements set to 1.0f).
- `mat4(float diagonal)` -> all diagonal elements set to `diagonal`.
- `mat4::orthographic(float left, float right, float bottom, float top, float near, float far)` -> returns an orthographic projection matrix.
- `mat4::perspective(float fov, float aspectRatio, float near, float far)` -> returns a perspective projection matrix.
## Other matrix functionality:
- `scale(const vec3& scalars)` -> scales the matrix.
- `rotate(float angle, const vec3& axis)` -> rotates the matrix.
- `translate(const vec3& translation)` -> translates the matrix.
- `lookAt(const vec3& camera, const vec3& target, const vec3& up)` -> defined inside sml.h and returns a lookAt matrix.
- Overloaded multiplication & shorthand counterpart.
- If you want to access the elements directly/get the pointer you can call `.data()` or use `&mat4[0][0]`.
- Almost all matrix manipulation functions can also be found inside sml.h if you prefer them over using member functions.
---
# Defines (defines.h):

SML also provides some defines you might potentially find useful:
- `SML_PI`
- `SML_PI_OVER_180`
- `SML_180_OVER_PI`



