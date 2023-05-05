var baseUrl = 'http://3.15.139.27:5005';
const url = "http://localhost:5005/dynamicArt/getEmotionPercentages";

window.onload = function() {
    const baseUrl = "http://3.15.139.27:5005";

    const canvas = document.getElementById("word-cloud");
    canvas.width = window.innerWidth;
    canvas.height = window.innerHeight;

    if (canvas.getContext) {
        const ctx = canvas.getContext("2d");

        fetchData().then(emotionData => {
            createWordCloud(emotionData, ctx);
        });
    }
};

async function fetchData() {
    const response = await fetch("http://3.15.139.27:5005/retrieve/words");
    const data = await response.json();
    return data.words;
}

function createWordCloud(emotionData, ctx) {
    const words = emotionData.map(word => {
        return {
            text: word,
            size: Math.random() * 50 + 20,
            color: getRandomColor(),
            x: Math.random() * ctx.canvas.width,
            y: Math.random() * ctx.canvas.height,
            speed: Math.random() * 3 + 1
        };
    });

    setInterval(() => {
        ctx.clearRect(0, 0, ctx.canvas.width, ctx.canvas.height);
        words.forEach(word => {
            ctx.font = `${word.size}px Arial`;
            ctx.fillStyle = word.color;
            ctx.fillText(word.text, word.x, word.y);
            word.x += word.speed;
            if (word.x > ctx.canvas.width) {
                word.x = -ctx.measureText(word.text).width;
                word.y = Math.random() * ctx.canvas.height;
            }
        });
    }, 24);
}

function getRandomColor() {
    const colors = ["#648FFF", "#785EF0", "#DC267F", "#FE6100", "#FFB000"];
    return colors[Math.floor(Math.random() * colors.length)];
}
