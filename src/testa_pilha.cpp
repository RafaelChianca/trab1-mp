#define CATCH_CONFIG_MAIN
#ifndef PILHA_H_
  #define PILHA_H_
  #include "pilha.h"
#endif
#ifndef _Catch
  #define _Catch
  #include "catch.hpp"
#endif

TEST_CASE( "Tests for push and pop", "[pushpop]" ) {
  
  StackNode *stack = CreateStack(3);
  
  Push(&stack, 10);
  REQUIRE( Top(stack) == 10 );

  Push(&stack, 20);
  Push(&stack, 30);
  Pop(&stack);
  REQUIRE( Top(stack) == 20 );

  Push(&stack, 40);
  Push(&stack, 50);
  REQUIRE( Top(stack) == 40 ); 
}