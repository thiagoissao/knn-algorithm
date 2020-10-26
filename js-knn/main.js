const lineReader = require('line-reader')

const PATH = '../bases/test_59.data'

const getClass = (data, k) => data[k]

const init = (path, k) => {
  lineReader.eachLine(path, (line, last) => {
    const data = line.split(',')
    const knnClass = getClass(data, k)
    console.log(knnClass)
  }, err => {
    if (err) console.error(err)
  })
}

//Inicia nessa função
init(PATH, 59)
