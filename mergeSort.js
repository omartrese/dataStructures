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
    
    left = array.splice(0, (array.length / 2) - 1)
    right = array.splice()

    return merge(mergeSort(left), mergeSort(right))
}


array = mergeSort(array)

console.log(array)
