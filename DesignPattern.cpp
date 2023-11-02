#include "DesignPattern.h"

#include <time.h>

namespace DP {
// 初始化静态变量，必要

DP::Singleton::HungrySingletonwithGC
    *DP::Singleton::HungrySingletonwithGC::instance =
        new Singleton::HungrySingletonwithGC();
DP::Singleton::LazySingletonwithGC
    *DP::Singleton::LazySingletonwithGC::instance = nullptr;

DP::Singleton::LazySingletonwithGC::GC
    DP::Singleton::LazySingletonwithGC::gc_singleton{};

DP::Singleton::HungrySingletonwithGC::GC
    DP::Singleton::HungrySingletonwithGC::gc_singleton{};

} // namespace DP

int main() {
  srand(time(0));
  std::cout << ">>>>>>>>>>>>>> Design Pattern <<<<<<<<<<<<<<" << std::endl;
  std::cout << std::endl;

  std::cout << "========== Builder Pattern ==========" << std::endl;
  DP::Builder::KFC *kfc = new DP::Builder::KFC{};
  DP::Builder::MealBuilder *builder = new DP::Builder::MealBuilderA{};
  kfc->setBuilder(builder);
  kfc->Cook();
  delete kfc;
  delete builder;
  std::cout << "=======================================" << std::endl;
  std::cout << std::endl;

  std::cout << "========== Prototype Pattern ==========" << std::endl;
  DP::Prototype::Student *Bob = new DP::Prototype::PrimaryStudent(
      "Bob", 9, new DP::Prototype::School{"schoolA"});
  DP::Prototype::Student *Lily = Bob->clone();
  Lily->setName("Lily");
  Lily->setAge(10);
  Lily->setSchool(new DP::Prototype::School{"schoolB"});
  Bob->introduce();
  Lily->introduce();
  delete Bob;
  delete Lily;
  std::cout << "=======================================" << std::endl;
  std::cout << std::endl;

  std::cout << "========== Singleton Pattern ==========" << std::endl;
  DP::Singleton::HungrySingletonwithGC::getInstance()->use();
  DP::Singleton::LazySingletonwithGC::getInstance()->use();
  DP::Singleton::SingletonwithoutGC::getInstance().use();
  std::cout << "=======================================" << std::endl;
  std::cout << std::endl;

  std::cout << "========== Decorator Pattern ==========" << std::endl;
  DP::Decorator::Transformer *tf_car = new DP::Decorator::Car{};
  DP::Decorator::Transformer *car_robot = new DP::Decorator::Robot(tf_car);
  DP::Decorator::Transformer *car_plane = new DP::Decorator::Plane(car_robot);
  car_robot->move();
  car_plane->move();
  delete tf_car;
  delete car_robot;
  delete car_plane;
  std::cout << "=======================================" << std::endl;
  std::cout << std::endl;

  std::cout << "========== Flyweight Pattern ==========" << std::endl;
  DP::Flyweight::FlyweightFactory *fwc = new DP::Flyweight::FlyweightFactory();
  fwc->getSharedFlyweight("no.1")->use();
  fwc->getSharedFlyweight("no.2")->use();
  fwc->getSharedFlyweight("no.1")->use();
  delete fwc;
  std::cout << "=======================================" << std::endl;
  std::cout << std::endl;

  std::cout << "========== Responsibility Pattern ==========" << std::endl;
  DP::Responsibility::Handler *PL = new DP::Responsibility::HandlerA{"PL"};
  DP::Responsibility::Handler *PM = new DP::Responsibility::HandlerB{"PM"};
  DP::Responsibility::Handler *Boss = new DP::Responsibility::HandlerC{"Boss"};
  PL->setNext(PM);
  PM->setNext(Boss);
  std::vector<int> requests{10, -5, 7, 200, 50};
  for (auto &r : requests) {
    PL->request(r);
    std::cout << std::endl;
  }
  delete PL;
  delete PM;
  delete Boss;
  std::cout << "=======================================" << std::endl;
  std::cout << std::endl;

  std::cout << "========== Command Pattern ==========" << std::endl;
  std::shared_ptr<DP::Command::Television> tv{
      std::make_shared<DP::Command::Television>()};
  DP::Command::Controller *controller = new DP::Command::Controller{};
  std::shared_ptr<DP::Command::Command> open =
      std::make_shared<DP::Command::OpenCommand>(tv);
  controller->setCommand(open);
  controller->use();
  std::shared_ptr<DP::Command::Command> change =
      std::make_shared<DP::Command::ChangeCommand>(tv);
  controller->setCommand(change);
  controller->use();
  std::shared_ptr<DP::Command::Command> off =
      std::make_shared<DP::Command::OffCommand>(tv);
  controller->setCommand(off);
  controller->use();
  delete controller;
  std::cout << "=======================================" << std::endl;
  std::cout << std::endl;

  std::cout << "========== Interpreter Pattern ==========" << std::endl;
  DP::Interpreter::Context *c = new DP::Interpreter::Context{};
  DP::Interpreter::Variable *a = new DP::Interpreter::Variable{};
  DP::Interpreter::Variable *b = new DP::Interpreter::Variable{};
  DP::Interpreter::Variable *d = new DP::Interpreter::Variable{};
  c->add(a, 5);
  c->add(b, 9);
  c->add(d, 8);
  DP::Interpreter::Expression *ex =
      new DP::Interpreter::Add(a, new DP::Interpreter::Minus(b, d));
  std::cout << "ex = " << ex->interpret(c) << std::endl;
  delete c;
  delete ex;
  std::cout << "=======================================" << std::endl;
  std::cout << std::endl;

  std::cout << "========== Iterator Pattern ==========" << std::endl;
  DP::Iterator::Object *student = new DP::Iterator::List{};
  student->push("Andrea");
  student->push("Bob");
  student->push("Lily");
  student->push("Terry");
  DP::Iterator::Iterator *it = student->CreateIterator();
  int index{0};
  while (!it->end()) {
    std::cout << "No." << index + 1 << " is " << it->next() << std::endl;
    ++index;
  }
  delete student;
  std::cout << "=======================================" << std::endl;
  std::cout << std::endl;

  std::cout << "========== Mediator Pattern ==========" << std::endl;
  DP::Mediator::Member *ma = new DP::Mediator::MemeberA();
  DP::Mediator::Member *mb = new DP::Mediator::MemeberB();
  DP::Mediator::IMediator *pm = new DP::Mediator::Mediator();
  pm->regist(1, ma);
  pm->regist(2, mb);
  ma->sendMessage(2, "Hello, I am A");
  mb->sendMessage(1, "Hello, I am B");
  delete ma;
  delete mb;
  delete pm;
  std::cout << "=======================================" << std::endl;
  std::cout << std::endl;

  std::cout << "========== Memento Pattern ==========" << std::endl;
  DP::Memento::Player *Ricardo = new DP::Memento::Player{};
  DP::Memento::SL *Devil = new DP::Memento::SL{};
  Ricardo->Init();
  Ricardo->Display();
  Devil->set("Init", Ricardo->Save());
  Ricardo->Fusion();
  Ricardo->Display();
  Devil->set("Fusion", Ricardo->Save());
  Ricardo->Fight();
  Ricardo->Display();
  Ricardo->Load(Devil->get("Init"));
  Ricardo->Display();
  Ricardo->Load(Devil->get("Fusion"));
  Ricardo->Display();
  delete Ricardo;
  delete Devil;
  std::cout << "=======================================" << std::endl;
  std::cout << std::endl;

  std::cout << "========== Observer Pattern ==========" << std::endl;
  DP::Observer::Subject *police = new DP::Observer::Police();
  DP::Observer::Observer *thief = new DP::Observer::Thief();
  DP::Observer::Observer *people = new DP::Observer::Someone();
  police->attach(thief);
  police->attach(people);
  police->action();
  delete police;
  delete thief;
  delete people;
  std::cout << "=======================================" << std::endl;
  std::cout << std::endl;

  std::cout << "========== State Pattern ==========" << std::endl;
  DP::State::Machine *machine = new DP::State::Machine{};
  machine->action();
  machine->get();
  machine->action();
  machine->get();
  machine->action();
  machine->get();
  machine->action();
  machine->get();
  delete machine;
  std::cout << "=======================================" << std::endl;
  std::cout << std::endl;

  std::cout << "========== Visitor Pattern ==========" << std::endl;
  DP::Visitor::School *Cassell = new DP::Visitor::School{};
  DP::Visitor::GCard *Fin = new DP::Visitor::GCard{};
  DP::Visitor::SCard *Lu = new DP::Visitor::SCard{};
  Cassell->push(Fin);
  Cassell->push(Lu);
  DP::Visitor::Lab *lab = new DP::Visitor::Lab{};
  DP::Visitor::Room *room = new DP::Visitor::Room{};
  DP::Visitor::Train *train = new DP::Visitor::Train{};
  Cassell->accept(lab);
  Cassell->accept(room);
  Cassell->accept(train);
  delete Cassell;
  delete Fin;
  delete Lu;
  delete lab;
  delete room;
  delete train;
  std::cout << "=======================================" << std::endl;
  std::cout << std::endl;

  std::cout << "========== TemplateMethod Pattern ==========" << std::endl;
  DP::TemplateMethod::Customer *Mike = new DP::TemplateMethod::Normal{};
  DP::TemplateMethod::Customer *Andrew = new DP::TemplateMethod::VIP{};
  Mike->shopping();
  Andrew->shopping();
  delete Mike;
  delete Andrew;
  std::cout << "=======================================" << std::endl;
  std::cout << std::endl;

  return 0;
}
