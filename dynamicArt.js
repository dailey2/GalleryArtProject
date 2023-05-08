var baseUrl = 'http://3.15.139.27:5005';

const emotionData = {
  "Happiness": 24,
  "Disgust": 15,
  "Fear": 10,
  "Surprise": 5,
  "Anger": 20,
  "Sadness": 15
};

const colr = {
  "Happiness": "yellow",
  "Surprise": "pink",
  "Disgust": "green",
  "Fear": "dark red","Sadness":"blue","":"white"
};

window.onload = function() {
  const canvas = document.getElementById('word-cloud');

  const w = window.innerWidth;
  const h = window.innerHeight;

  canvas.width = w;
  canvas.height = h;

  const ctx = canvas.getContext('2d');


  const word_attr = createWordData(emotionData);

  function animation() {
    for (let i = 0; i < word_attr.length; i++) {
      const word = word_attr[i];
      ctx.font = word.font;
      ctx.fillStyle = word.color;
      ctx.fillText(word.text, word.x, word.y);
      word.width = ctx.measureText(word.text).width;
      ctx.stroke();
    }
    move();
  }

  function move() {
    for (let i = 0; i < word_attr.length; i++) {
      const word = word_attr[i];
      if (word.x > w) {
        word.x = -word.width;
        word.y = Math.random() * h;
      } else {
        word.x += word.speed;
      }
    }
  }

  setInterval(function() {
    ctx.clearRect(0, 0, w, h);
    animation();
  }, 24);

  function createWordData(emotionData) {
    const words = [];
    for (const emotion in emotionData) {
      const count = emotionData[emotion];
      for (let i = 0; i < count; i++) {
        const word = criteria(emotion);
        if (!overlapping(word.x, word.y, word.width, words)) {
          words.push(word);
        }
      }
    }
    return words;
  }

  function criteria(key) {
    const word = {};
    word.text = key;
    word.x = Math.random() * w;
    word.y = Math.random() * h;
    word.font = emotionData[key] * 5 + 'px Arial';
    word.speed = emotionData[key] / 10;
    word.color = colr[key];
    word.width = 0;
    return word;
  }

  function overlapping(x, y, size, placedWords) {
    for (let i = 0; i < placedWords.length; i++) {
      const word = placedWords[i];
      const distance = Math.sqrt((x - word.x) ** 2 + (y - word.y) ** 2);
      if (distance < (size + word.width) / 2) {
        return true;
      }
    }
    return false;
  }
};
