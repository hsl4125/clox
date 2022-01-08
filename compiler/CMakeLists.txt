add_library(Compiler
  SHARED
  )

target_sources(Compiler
  PRIVATE
  memory.c
  chunk.c
  debug.c
  value.c
  )

