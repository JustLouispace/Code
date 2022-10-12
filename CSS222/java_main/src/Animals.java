class Animal {
    public void speak() {
        System.out.println("Animal Speak !");
    }

    class Dog extends Animal {
        public void speak() {
            bark();
        }

        public void bark() {
            System.out.println("Woof !");
        }
    }

    class Seal extends Animal {
        public void bark() {
            System.out.println("Arf !");
        }
    }

    class Bird extends Animal {
    public void speak () { 
        System.out.println("Tweet !");
        }
    }
}