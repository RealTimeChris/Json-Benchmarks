// Glaze Library
// For the license information refer to glaze.hpp

#pragma once

namespace glz
{
   enum class error : uint32_t
   {
      none,
      Read,
      write,
      maximum_size_exceeded,
      mismatching_dimensions
   };
}
