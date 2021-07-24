#include<stdio.h>
#include "PrintName.h"

JNIEXPORT void JNICALL Java_PrintName_printName
  (JNIEnv *env, jclass this, jstring name){

  const char * myName = (*env)->GetStringUTFChars(env, name, 0);
  printf("[C++]My Name is :- %s.\n", myName);
  (*env)->ReleaseStringUTFChars(env, name, myName);
    
}

JNIEXPORT void JNICALL Java_PrintName_greeting
  (JNIEnv *env, jclass this){

  printf("[C++]Greeting from C world.\n");
    
}

JNIEXPORT jint JNICALL Java_PrintName_add
  (JNIEnv *env, jclass this, jint num1, jint num2){

  printf("[C++]Adding %d and %d.\n", num1, num2);
  return num1+num2;
    
}

// According to link: https://stackoverflow.com/questions/13796786/jstring-return-in-jni-program
// @nn0p When using env functions in c, the statement is (*env)->Function(env, parameters). However in c++, this turns to: env->Function(parameters). – agastalver Nov 7 '16 at 13:02

JNIEXPORT jstring JNICALL Java_PrintName_append
  (JNIEnv *env, jclass this, jstring str1, jstring str2){

  const char * myStr1 = (*env)->GetStringUTFChars(env, str1, NULL);
  printf("[C++]String1 is :- %s.\n", myStr1);

  const char * myStr2 = (*env)->GetStringUTFChars(env, str2, 0);
  printf("[C++]String2 is :- %s.\n", myStr2);

  // jstring retVal = str1 + str2;
  jstring retVal;

  char msg[600] = "[C++]COMBINED MSG :";

  strcat(msg, myStr1);
  strcat(msg, myStr2);

  puts(msg);

  retVal = (*env)->NewStringUTF(env,msg);

  (*env)->ReleaseStringUTFChars(env, str1, myStr1);
  (*env)->ReleaseStringUTFChars(env, str2, myStr2);

  return retVal;

  }