const returnValue = ["false", "true"];

function generate(n){
    let code =  "function isOdd(num){\n\tif (isNaN(num)) {\n\t\tthrow \"Input value is not a number!\";\n\t} else {";
    for(let i=0; i<n; i++){
        code += "\n\t\tif(num === " + i + "){\n\t\t\treturn " + returnValue[i%2] + ";\n\t\t}"; 
    }
    code += "\n\t}\n}";
    return code;
}

console.log(generate(1000000000))