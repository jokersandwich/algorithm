int mySqrt(int a) {
    if (a == 0) return a;
    int l = 1, r = a, mid, sqrt;
    while (l <= r) {
        mid = l + (r - l) / 2;
        sqrt = a / mid;
        if (sqrt == mid) {
            return mid;
        } else if (mid > sqrt) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return r;
}

// c++版本更好，防止溢出
// javascript版本的l+r和mid*mid计算都有可能导致溢出

// 还没完全想清楚小数是怎么处理的？

// 注意：加法和乘法要小心溢出（加法溢出会怎样，从CSAPP的角度想想）

// 心得：二分法查找更快，是因为有额外的信息——有序。

// javascript
/**
 * @param {number} x
 * @return {number}
 */
var mySqrt = function(x) {
    let l = 1, r = x;
    while (l <= r) {
        const mid = Math.floor((l + r) / 2);
        const square = mid * mid;
        if (square === x) {
            return mid;
        } else if (square > x) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return r;
};
