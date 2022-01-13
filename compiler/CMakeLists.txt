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
  compiler.c
  scanner.c
  object.c
  table.c
  )

