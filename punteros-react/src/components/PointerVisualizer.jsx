import { useState } from 'react';
import { motion as Motion } from 'framer-motion';

const cells = Array.from({ length: 5 }, (_, i) => i);

export default function PointerVisualizer() {
  const [index, setIndex] = useState(0);

  const move = (dir) => {
    setIndex((i) => {
      const next = i + dir;
      if (next < 0) return 0;
      if (next >= cells.length) return cells.length - 1;
      return next;
    });
  };

  return (
    <div className="pointer-demo">
      <div className="memory">
        {cells.map((c, i) => (
          <div key={i} className="cell">
            {i}
          </div>
        ))}
        <Motion.div
          className="pointer"
          layout
          initial={{ x: 0 }}
          animate={{ x: index * 60 }}
          transition={{ type: 'spring', stiffness: 300, damping: 20 }}
        >
          ↕
        </Motion.div>
      </div>
      <div className="controls">
        <button onClick={() => move(-1)}>◀️</button>
        <button onClick={() => move(1)}>▶️</button>
      </div>
    </div>
  );
}
