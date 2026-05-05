void swap(char* a, char* b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}
void reverse(char* l, char* r) {
    while (l <= r) {
        swap(l, r);
        l++;
        r--;
    }
}
int compress(char* chars, int charsSize) {
    char* write = chars;
    char* left = chars;
    char* read = chars;
    while(read-chars<charsSize) {
        int count = 0;
        while (read<chars+charsSize&&(*read)==(*left)) {
            count++;
            read++;
        }
        left = read;
        *write = *(read-1);
        write++;
        if(count>1){
            char* idx = write;
            while (count > 0) {
                *write = count%10+'0';
                count /= 10;
                write++;
            }
            reverse(idx,write-1);
        }
    }
    return write-chars;
}
