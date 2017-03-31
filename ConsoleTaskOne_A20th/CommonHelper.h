#pragma once

#include "string"
#include "iostream"

using namespace std;

const string systemBegin = "------------------------------ SYSMESSAGE ";
const string systemEnd = " ------------------------------";

void PrintError(string text, string title);
int Random(int min, int max);
int Abs(int value);