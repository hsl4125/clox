add_executable(repl)

target_sources(repl
  PRIVATE
  repl.c
  )

target_link_libraries(repl
  PRIVATE
  Compiler
  )

