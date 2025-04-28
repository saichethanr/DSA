type F = (x: number) => number;

function compose(functions: F[]): F {
    if(functions.length==0){
        return (x:any) => x;
    }
    return functions.reduceRight((prevFun,NextFun): F =>{
        return (x:any) => {
            return NextFun(prevFun(x));
        };
    });

};

/**
 * const fn = compose([x => x + 1, x => 2 * x])
 * fn(4) // 9
 */