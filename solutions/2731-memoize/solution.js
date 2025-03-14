/**
 * @param {Function} fn
 * @return {Function}
 */
function memoize(fn) {
    let cache = {};
    let getCallCount = 0;
    return function(...args) {
        const key = JSON.stringify(args);
        if(cache.hasOwnProperty(key)){
            return cache[key];
        }
        const res = fn(...args);
        cache[key] = res;
        getCallCount++;
        return res;
    };
}


/** 
 * let callCount = 0;
 * const memoizedFn = memoize(function (a, b) {
 *	 callCount += 1;
 *   return a + b;
 * })
 * memoizedFn(2, 3) // 5
 * memoizedFn(2, 3) // 5
 * console.log(callCount) // 1 
 */
