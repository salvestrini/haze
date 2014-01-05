macro(haze_set_option var default type docstring)

    if(NOT DEFINED ${var})
      set(${var} ${default})
    endif()
    set(${var} ${${var}} CACHE ${type} ${docstring} FORCE)

endmacro()
