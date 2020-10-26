const lineReader = require('line-reader')

const PATH = '../bases/test_59.data'
lineReader.eachLine(PATH, (line, last) => {
  console.log(line)
})
