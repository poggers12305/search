#ifndef SEARCHFUNCTIONS_H
#define SEARCHFUNCTIONS_H

bool binarySearch(LIST *data, int key, int *location);
nodePtr findMid(LIST *L, int l, int h);
bool linearSearch(LIST *data, int key, int *location);

#endif
