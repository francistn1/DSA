void reverseString(char* s, int sSize) {
    char* rev = (char*)malloc(sSize * sizeof(char));
    int k = 0;
    for(int i = sSize - 1; i >= 0; i--) {
        rev[k++] = s[i];
    }
    for(int i = 0; i < k; i++){
        s[i] = rev[i];
    }

    free(rev);
}