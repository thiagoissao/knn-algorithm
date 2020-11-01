const fs = require('fs')

const getParams = () => {
  const TRAIN_PATH = process.argv[2]
  const TEST_PATH = process.argv[3]
  const K = process.argv[4]

  if (!TRAIN_PATH || !TEST_PATH || !K) {
    console.error('Passagem incorreta de parâmetros!!')
    console.error('Ex: ../train_59.data ../test_59.data 10\n ')
    return {
      TRAIN_PATH: undefined,
      TEST_PATH: undefined,
      K: undefined
    }
  }
  return { TRAIN_PATH, TEST_PATH, K }
}

const getDatabases = (trainPath, testPath) => {
  let trainDatabase = fs.readFileSync(trainPath, { encoding: 'utf8', flag: 'r' }).split('\n')
  trainDatabase.pop() //remove pois é uma string vazia por causa da última linha do arquivo
  let testDatabase = fs.readFileSync(testPath, { encoding: 'utf8', flag: 'r' }).split('\n')
  testDatabase.pop() //remove pois é uma string vazia por causa da última linha do arquivo
  return {
    train: trainDatabase,
    test: testDatabase
  }
}

const getDistances = databases => {
  const { train, test } = databases

  const sortedDistances = test.map(rowTest => {
    const itemTest = rowTest.split(',')
    itemTest.pop() //Remove class

    const exponentiations = train.map(rowTrain => {
      const itemTrain = rowTrain.split(',')
      const classe = itemTrain.pop() //Remove class
      const values = itemTrain.map((columnTrain, index) => {
        if (typeof +columnTrain === 'number' && typeof +itemTest === 'number') {
          const subtract = itemTest[index] - columnTrain
          return Math.pow(subtract, 2)
        }
        return 0
      })
      return ({ classe, values })
    })

    const euclidianaDistances = exponentiations.map(exp => ({ class: exp.classe, distance: Math.sqrt(exp.values.reduce((acc, cur) => acc += cur, 0)) }))
    return euclidianaDistances.sort((a, b) => a.distance - b.distance)
  })
  return sortedDistances
}

const findClasses = (sortedDistances, k) => {
  const classesCounts = sortedDistances.map(item =>
    item.slice(0, k).reduce((acc, curr) => ({
      ...acc,
      [curr.class]: acc[curr.class] = acc[curr.class] + 1
    }), {
      samba: 0,
      sertanejo: 0,
      forro: 0,
      rap: 0,
      axe: 0,
      bossa_nova: 0
    })
  )
  const definitive = classesCounts.map(item => {
    let highest = -Infinity;
    let key;
    Object.entries(item).forEach(([nameClass, quantity]) => {
      if (item[nameClass] > highest) {
        highest = quantity;
        key = nameClass;
      }
    })
    return key;
  })

  return definitive
}

//Chamadas das funções
const { TRAIN_PATH, TEST_PATH, K } = getParams()
const databases = getDatabases(TRAIN_PATH, TEST_PATH)
const sortedDistances = getDistances(databases, K)
const result = findClasses(sortedDistances, K)

console.log(result)
