//Kiểm tra một số có phải là số lẻ hay không theo một cách thật khác bọt
function isOdd(num) {
    if (isNaN(num)) {
        throw "Input value is not a number!";
    } else {
        if (num === 0) {
            return false;
        }
        if (num === 1) {
            return true;
        }
        if (num === 2) {
            return false;
        }
    }
}