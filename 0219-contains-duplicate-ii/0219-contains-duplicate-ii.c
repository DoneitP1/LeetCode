struct hash_struct {
    int id;
    int value;
    UT_hash_handle hh;
};

bool containsNearbyDuplicate(int* nums, int numsSize, int k){
    struct hash_struct *map = NULL;
    for(int i = 0; i < numsSize; i++){
        struct hash_struct *temp;
        HASH_FIND_INT(map, &nums[i], temp);
        if(temp == NULL){
            temp = (struct hash_struct *)malloc(sizeof(struct hash_struct));
            temp -> id = nums[i];
            temp -> value = i;
            HASH_ADD_INT(map, id, temp);
        } else {
            if((i - temp -> value) <= k) {
                return true;
            } else {
                temp -> value = i;
            }
        }
    }
    return false;
}