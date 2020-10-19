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

TEST_CASE( "Tests for stack size", "[size]" ) {
  
  StackNode *stack = CreateStack(5);

  REQUIRE( StackSize(stack) == 0 );
  
  Push(&stack, 10);
  REQUIRE( StackSize(stack) == 1 );

  Push(&stack, 20);
  Push(&stack, 30);
  REQUIRE( StackSize(stack) == 3 );

  Pop(&stack);
  REQUIRE( StackSize(stack) == 2 );
}

TEST_CASE( "Tests for IsEmpty and IsFull", "[emptyfull]" ) {
  
  StackNode *stack = CreateStack(3);

  REQUIRE( IsEmpty(stack) == 1 );

  Push(&stack, 10);
  REQUIRE( IsEmpty(stack) == 0 );
  REQUIRE( IsFull(stack) == 0 );

  Push(&stack, 20);
  Push(&stack, 30);
  REQUIRE( IsFull(stack) == 1 );
}

TEST_CASE( "Tests for SetSize", "[setsize]" ) {
  
  StackNode *stack = CreateStack(1);

  REQUIRE( IsEmpty(stack) == 1 );

  Push(&stack, 10);
  REQUIRE( IsEmpty(stack) == 0 );
  REQUIRE( IsFull(stack) == 1 );

  SetSize(&stack, 3);
  REQUIRE( IsFull(stack) == 0 );

  Push(&stack, 20);
  Push(&stack, 30);
  REQUIRE( IsFull(stack) == 1 );

  DeleteStack(&stack);
  REQUIRE( SetSize(&stack, 10) == 0 );

}

TEST_CASE( "Tests for DeleteStack", "[delete]" ) {
  
  StackNode *stack = CreateStack(3);

  REQUIRE( IsEmpty(stack) == 1 );

  Push(&stack, 10);
  Push(&stack, 20);
  Push(&stack, 30);
  REQUIRE( IsFull(stack) == 1 );
  REQUIRE( StackSize(stack) == 3 );

  DeleteStack(&stack);
  REQUIRE( StackSize(stack) == 0 );
  REQUIRE( IsFull(stack) == 0 );
  REQUIRE( IsEmpty(stack) == 1 );
}