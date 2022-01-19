import express from 'express';
import ping from './ping';

const app = express();
const port = 3000;

app.use('/ping', ping);

app.listen(port, () => {
  return console.log(`Express is listening at http://localhost:${port}`);
});