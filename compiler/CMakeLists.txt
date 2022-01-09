add_library(Compiler
  SHARED
  ${HEADER_FILES}
  )


target_sources(Compiler
  PRIVATE
  memory.c
  chunk.c
  debug.c
  value.c
  vm.c
  )

