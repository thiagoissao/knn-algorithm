const TRAIN_PATH = '../bases/train_59_small.data'
const TEST_PATH = '../bases/test_59_small.data'
const K = 10

const fs = require('fs')

const init = (trainPath, testPath) => {
  let trainDatabase = fs.readFileSync(trainPath, { encoding: 'utf8', flag: 'r' }).split('\n')
  trainDatabase.pop() //remove pois é uma string vazia por causa da última linha do arquivo
  let testDatabase = fs.readFileSync(testPath, { encoding: 'utf8', flag: 'r' }).split('\n')
  testDatabase.pop() //remove pois é uma string vazia por causa da última linha do arquivo
  return {
    train: trainDatabase,
    test: testDatabase
  }
}

const execute = (databases, k) => {
  const { train, test } = databases
  let trainClasses = []

  const sortedDistances = test.map(rowTest => {
    const itemTest = rowTest.split(',')
    itemTest.pop() //Remove class
    const exponentiations = train.map(rowTrain => {
      const itemTrain = rowTrain.split(',')
      trainClasses.push(itemTrain.pop()) //Remove class
      return itemTrain.map((columnTrain, index) => {
        if (typeof +columnTrain === 'number' && typeof +itemTest === 'number') {
          const subtract = itemTest[index] - columnTrain
          return Math.pow(subtract, 2)
        }
        return 0
      })
    })
    const euclidianaDistances = exponentiations.map(exp => Math.sqrt(exp.reduce((acc, cur) => acc += cur, 0)))
    return euclidianaDistances.sort()
  })

  console.log(sortedDistances)
}

//Chamadas das funções
const databases = init(TRAIN_PATH, TEST_PATH)
execute(databases, K)
