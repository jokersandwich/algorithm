public class CollisionSystem {
    private static final double HZ = 0.5;

    private MinPQ<Event> pq;
    private double t = 0.0;
    private Particle[] particles;

    public CollisionSystem(Particle[] particles) {
        this.particles = particles.clone();
    }

    private void predict(Particle a, double limit) {
        if (a == null) return;

        for (int i = 0; i < particles.length; i++) {
            double dt = a.timeToHit(particles[i]);
            if (t + dt <= limit) {
                pq.insert(new Event(t + dt, a, particles[i]));
            }
        }

        double dtX = a.timeToHitVerticalWall();
        double dtY = a.timeToHitHorizontalWall();
        if (t + dtX <= limit) pq.insert(new Event(t + dtX, a, null));
        if (t + dtY <= limit) pq.insert(new Event(t + dtY, null, a));
    }

    private void redraw(double limit) {
        StdDraw.clear();
        for (int i = 0; i < particles.length; i++) {
            particles[i].draw();
        }
        StdDraw.show();
        StdDraw.pause(20);
        if (t < limit) {
            pq.insert(new Event(t + 1.0 / HZ, null, null));
        }
    }
    
    public void simulate(double limit) {
        pq = new MinPQ<Event>();
        for (int i = 0; i < particles.length; i++) {
            predict(particles[i], limit);
        }
        pq.insert(new Event(0, null, null));

        while (!pq.isEmpty()) {
            Event e = pq.delMin();
            if (!e.isValid()) continue;
            Particle a = e.a;
            Particle b = e.b;

            for (int i = 0; i < particles.length; i++) {
                particles[i].move(e.time - t);
            }
            t = e.time;

            if      (a != null && b != null) a.bounceOff(b);
            else if (a != null && b == null) b.bounceOffVerticalWall();
            else if (a == null && b != null) b.bounceOffHorizontalWall();
            else if (a == null && b == null) redraw(limit);

            predict(a, limit);
            predict(b, limit);
        }
    }

    private static class Event implements Comparable<Event> {
        private final double time;
        private final Particle a, b;
        private final int countA, countB;

        public Event(double t, Particle a, Particle b) {
            this.time = t;
            this.a    = a;
            this.b    = b;
            if (a != null) countA = a.count();
            else           countA = -1;
            if (b != null) countB = b.count();
            else           countB = -1;
        }

        public int compareTo(Event that) {
            return Double.compare(this.time, that.time);
        }

        public boolean isValid() {
            if (a != null && a.count() != countA) return false;
            if (b != null && b.count() != countB) return false;
        }
    }
}