const processedFrame = document.getElementById('processed-frame') as HTMLImageElement;
const stats = document.getElementById('stats');

// Dummy data
const dummyBase64Image = ""; // Replace with a base64 encoded image
const dummyStats = {
    fps: 15,
    resolution: "640x480"
};

processedFrame.src = `data:image/jpeg;base64,${dummyBase64Image}`;
stats.innerHTML = `FPS: ${dummyStats.fps}, Resolution: ${dummyStats.resolution}`;
