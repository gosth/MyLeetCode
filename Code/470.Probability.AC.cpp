// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7
/*
从rand大数可以转换成任意rand小数
所以只要把rand7()改成rand49()或任意比10大的随机数生成方法，但是一定要均匀，就可以实现rand10()
证明：通过该方法从rand49()转换为rand10()的过程中，获取单一项（如1）的概率为
P(1) = (1/49) + (39/49) * (1/49) + (39/49) * (39/49) * (1/49) + ....
= (1/49) * （1 + （39/49) + (39/49)^2 + ... + (39/49)^n)
= (1/49) * (49/10)
= 1/10
*/
class Solution {
public:
    int rand10() {
        int result = (rand7() - 1) * 7 + rand7(); // 相当于rand49()
        while (result > 10) {
            result = (rand7() - 1) * 7 + rand7();
        }
        return result;
    }
};