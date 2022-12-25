let array = [2, 32, 43, 1, 6, 74, 11, 3]

console.log(array.length)
console.log(array)

function merge(left, right)
{
    let result = []

    while(left.length && right.length)
    {
        if(left[0] > right[0])
        {
            result.push(right.shift())
        } else result.push(left.shift())
    }

    return [...result, ...left, ...right]
    
}

function mergeSort(array) 
{
    if(array.length <= 1) return array
    
    let left = mergeSort(array.slice(0, array.length / 2))
    let right = mergeSort(array.slice(array.length / 2))

    return merge(left, right)
}


array = mergeSort(array)

console.log(array)
