/*******************************************************************************
* Filename: configureTeam.hpp                                                  *
* Author:   Daniel Wilson                                                      *
* E-Mail:   wilsond3@oregonstate.edu                                           *
* Date:     27 May 2017                                                        *
*                                                                              *
* Description: Provides the prototypes to functions that are used to allow the *
*    user to configure their team rosters.                                     *
*                                                                              *
*******************************************************************************/

#ifndef CONFIGURE_TEAM_HPP
#define CONFIGURE_TEAM_HPP

#include "CreatureQueue.hpp"

void pickTeamSize(int& teamSize, bool anyTeamSet = false);
void printSettings(int teamSize);
void configureTeam(CreatureQueue& roster, int teamSize, char team);
void addToRoster(CreatureQueue& roster, int menuSelection, char team);
void printTeamConfigStatus(CreatureQueue& teamOneRoster, 
                           CreatureQueue& teamTwoRoster);

#endif // CONFIGURE_TEAM_HPP
