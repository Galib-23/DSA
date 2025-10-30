class TimeLimitedCache {
  constructor() {
    this.keyMap = new Map();
  }
  set(key, value, duration) {
    const existing = this.keyMap.get(key);
    if(existing) {
      clearTimeout(existing.timeOutId);
    }
    const timeOutId = setTimeout(() => {
      this.keyMap.delete(key);
    }, duration);  
    this.keyMap.set(key, {value, timeOutId});
    if(existing) return true;
    else return false;
  }
  get(key) {
    const existing= this.keyMap.get(key);
    if(existing) return existing.value;
    else return -1;
  }
  count() {
    return this.keyMap.size;
  }
}


let array = ["hi","hello","how"];

let copyarray = array.slice();

let for1 = array.forEach((a) => {
  console.log(a);
});

 console.log(` 
  
  
  break
  
  
  `);

let for2 = copyarray.forEach((a) => {
  console.log(a);
});

 console.log(` 
  
  
  break
  
  
  `);

  for (i = 0; i < array.length; i++){
  console.log(array[i])
}



for1;



for2;