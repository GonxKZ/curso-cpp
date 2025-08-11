import './App.css';
import PointerVisualizer from './components/PointerVisualizer';
import { concepts } from './data/concepts';

export default function App() {
  return (
    <div>
      <h1>Punteros en C++</h1>
      {concepts.map(({ title, description }) => (
        <section key={title} className="card">
          <h2>{title}</h2>
          <p>{description}</p>
        </section>
      ))}
      <PointerVisualizer />
    </div>
  );
}
