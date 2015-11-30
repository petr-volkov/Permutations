//
// Created by petr_v on 30/11/2015.
//

#ifndef PERMUTATIONS_STR2INT_H
#define PERMUTATIONS_STR2INT_H

enum STR2INT_ERROR { STR2INT_SUCCESS, STR2INT_OVERFLOW, STR2INT_UNDERFLOW, STR2INT_INCONVERTIBLE };
STR2INT_ERROR str2int (long int &, char const *, int = 0);

#endif //PERMUTATIONS_STR2INT_H