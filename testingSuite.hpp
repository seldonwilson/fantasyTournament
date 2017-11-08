/*******************************************************************************
* Filename: testingSuite.hpp                                                   *
* Author:   Daniel Wilson                                                      *
* E-Mail:   wilsond3@oregonstate.edu                                           *
* Date:     27 May 2017                                                        *
*                                                                              *
* Description: Provides prototypes for functions which are used to test the    *
*    stack and queue.                                                          *
*                                                                              *
*******************************************************************************/

#ifndef TESTING_SUITE_HPP
#define TESTING_SUITE_HPP

void testSuite();
void testCreatureStack(int nodesToCreate);
void testCreatureQueue(int nodesToCreate);
void testQueuePopToStack(int nodesToCreate);
void testPushPop(int nodesToCreate);
void printNumberOfNodes(int numberOfNodes);
void testPushPopPushToStack(int numberOfNodes);
void setNumberOfTestNodes(int& numberOfNodes);

#endif // TESTING_SUITE_HPP
