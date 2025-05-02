const Controller = (() => {

    // Stores the connected gamepad
    let gp = null;
  
    // Tracks whether spacebar is down
    let spaceDown = false;
  
    // Stores the latest input values
    const s = {
      lx: 0, // left stick X
      ly: 0, // left stick Y
      rx: 0, // right stick X
      ry: 0, // right stick Y
      b1: false, // left stick pressed
      b2: false // right stick pressed OR spacebar
    };
  
    function init() {
      // Listen when a controller connects/disconnects
      window.addEventListener('gamepadconnected', e => gp = e.gamepad);
      window.addEventListener('gamepaddisconnected', () => gp = null);
  
      // Spacebar counts as button 2
      window.addEventListener('keydown', e => {
        if (e.code === 'Space') spaceDown = true;
      });
      window.addEventListener('keyup', e => {
        if (e.code === 'Space') spaceDown = false;
      });
  
      // Start checking input every frame
      requestAnimationFrame(loop);
    }
  
    // Run every frame to update the values
    function loop() {
      if (gp) {
        const g = navigator.getGamepads()[gp.index];
        if (g) {
          s.lx =  g.axes[0]; // left stick X (left/right)
          s.ly = -g.axes[1]; // left stick Y (up/down) flipped
          s.rx =  g.axes[2]; // right stick X
          s.ry =  -g.axes[5]; // right stick Y flipped (Changed from axes 3 to axes 5)
          s.b1 =  g.buttons[0].pressed; // button 1 (left stick click)
          s.b2 =  g.buttons[1].pressed || spaceDown; // button 2 or spacebar
        }
      }
      requestAnimationFrame(loop); // run again next frame
    }
  
    // return the current values
    return {
      init,
      getLeftX: () => s.lx,
      getLeftY: () => s.ly,
      getRightX: () => s.rx,
      getRightY: () => s.ry,
      isButton1Pressed: () => s.b1,
      isButton2Pressed: () => s.b2
    };
  })();
  
  // Use it like:
  // import { Controller } from './controller.js'
  export { Controller };
  
