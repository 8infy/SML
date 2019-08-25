# SML | [![Build status](https://ci.appveyor.com/api/projects/status/8k2haf6uy3st02c1?svg=true)](https://ci.appveyor.com/project/8infy/sml) | [![Codacy Badge](https://api.codacy.com/project/badge/Grade/2bec0a2cac70433eb3576a6b325b4441)](https://www.codacy.com/app/8infy/SML?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=8infy/SML&amp;utm_campaign=Badge_Grade) |

## A header-only math library intended for use with any rendering APIs out there. Uses GLSL syntax & column-major
---
## Please note
-   SML functions always expect degrees for angles/fov/anything and NOT radians!
-   It is recommended to include sml.h instead of including headers separately because you gain additional functionality & less cluttered translation unit.  
-   Most of the member functions (e.g `mat4::orthographic(...)`) have a stand-alone copy inside sml.h. Feel free to use whichever implementation is more comfortable.
---
## Vectors
-   `bvec2`, `bvec3`, `bvec4` - Vector of booleans values.
-   `ivec2`, `ivec3`, `ivec4` - Vector of integers.
-   `uvec2`, `uvec3`, `uvec4` - Vector of unsigned integers.
-   `vec2`, `vec3`, `vec4` - Vector of floating point values.
-   `dvec2`, `dvec3`, `dvec4` - Vector of double precision floating point values.  

Vector functionality  
-   Dot/cross product.
-   Normalization.
-   Magnitude.
-   Access to elements via `[]` or `data()`.  
---
## Matricies
-   `mat4` - 4x4 Matrix of floating point values.
-   `dmat4` - 4x4 Matrix of double precision floating point values.    

Matrix functionality
-   Identity matrix constructor.
-   Orthographic matrix constructor.
-   Perspective matrix constructor.
-   LookAt matrix constructor.
-   Matrix inverse.
-   Matrix scale.
-   Matrix translation.
-   Matrix rotation.
-   Access to elements via `[column][element]` or `elements[row + column * 4]` or `data()`.    
---
## Utility functions (functions defined inside utils.h)  
-   `T to_radians(T degrees)` -> converts degrees into radians.
-   `T to_degrees(T radians)` -> converts radians into degrees.  
---  
## Defines (defines.h)  
-   `SML_PI`
-   `SML_PI_OVER_180`
-   `SML_180_OVER_PI`
