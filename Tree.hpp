//talyape123@gmail.com
#ifndef TREE_HPP
#define TREE_HPP

#include "Node.hpp"
#include "Iterator.hpp"
#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>

template <typename T, size_t K>
class BaseTree {
protected:
    Node<T>* root;

public:
    BaseTree() : root(nullptr) {}

    void add_root(Node<T>* new_root) {
        root = new_root;
    }

    void add_sub_node(Node<T>* parent, Node<T>* child) {
       
        if (parent->get_childrens().size() >= K) {
            throw std::runtime_error("Parent already has maximum number of children.");
        }
        parent->add_child(child);
    }

    Node<T>* getRoot() const {
        return root;
    }

    bfs_scan_iterator<T> begin() {
        return begin_bfs_scan();
    }

    bfs_scan_iterator<T> end() {
        return end_bfs_scan();
    }

    bfs_scan_iterator<T> begin_bfs_scan() {
        return bfs_scan_iterator<T>(root);
    }

    bfs_scan_iterator<T> end_bfs_scan() {
        return bfs_scan_iterator<T>(nullptr);
    }

    dfs_scan_iterator<T> begin_dfs_scan() {
        return dfs_scan_iterator<T>(root);
    }

    dfs_scan_iterator<T> end_dfs_scan() {
        return dfs_scan_iterator<T>(nullptr);
    }

    // Template function to calculate the total levels in the tree
    int calcHight(Node<T> *node) {
        if (!node) {
            return 0;
        } else {
            int hight = 0;
            for (auto &child : node->children) {
                hight = std::max(hight, calcHight(child));
            }
            return hight + 1;
        }
    }

    // Template function to draw the tree
   void draw(int width, int height) {
        sf::RenderWindow window(sf::VideoMode(width, height), "Tree Visualization");
        sf::Font font;
        if (!font.loadFromFile("/usr/share/fonts/truetype/dejavu/DejaVuSans-Bold.ttf")) {
            std::cerr << "Could not load font" << std::endl;
            return;
        }

        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    window.close();
            }

            window.clear(sf::Color::White);
            drawTree(window, font);
            window.display();

            sf::sleep(sf::milliseconds(10));
        }
    }

private:
    void drawTree(sf::RenderWindow &window, sf::Font &font) {
        Node<T> *root = this->getRoot();
        if (!root) return;

        int totalLevels = calcHight(root);
        float nodeRadius = 20.0f;
        float verticalSpacing = (window.getSize().y - 2 * nodeRadius) / (totalLevels + 1);
        float horizontalSpacing = window.getSize().x / 2.0f;

        drawTreeNodesEdges(window, root, sf::Vector2f(window.getSize().x / 2.0f, nodeRadius + 10), horizontalSpacing, verticalSpacing, nodeRadius, font, 0, totalLevels);
    }

    void drawTreeNodesEdges(sf::RenderWindow &window, Node<T>* node, sf::Vector2f position, float horizontalSpacing, float verticalSpacing, float nodeRadius, sf::Font &font, int level, int totalLevels) {
        if (!node) return;

        // ציור העיגול
        sf::CircleShape shape(nodeRadius);
        shape.setFillColor(sf::Color::Green);
        shape.setOutlineColor(sf::Color::Black);
        shape.setOutlineThickness(2);
        shape.setPosition(position.x - nodeRadius, position.y - nodeRadius);
        window.draw(shape);

        // ציור הטקסט
        sf::Text text;
        text.setFont(font);
        text.setString(node->to_short_string());
        text.setCharacterSize(14);
        text.setFillColor(sf::Color::Black);
        sf::FloatRect textRect = text.getLocalBounds();
        text.setOrigin(textRect.left + textRect.width/2.0f, textRect.top + textRect.height/2.0f);
        text.setPosition(position);
        window.draw(text);

        // חישוב מיקומים לילדים
        float childrenSpacing = horizontalSpacing / std::pow(2, level + 1);
        float leftmostChildX = position.x - childrenSpacing * (node->get_childrens().size() - 1) / 2.0f;

        for (size_t i = 0; i < node->get_childrens().size(); ++i) {
            Node<T>* child = node->get_childrens()[i];
            if (child) {
                sf::Vector2f childPosition(leftmostChildX + i * childrenSpacing, position.y + verticalSpacing);

                // ציור הקו
                sf::Vertex line[] = {
                    sf::Vertex(sf::Vector2f(position.x, position.y + nodeRadius), sf::Color::Black),
                    sf::Vertex(sf::Vector2f(childPosition.x, childPosition.y - nodeRadius), sf::Color::Black)
                };
                window.draw(line, 2, sf::Lines);

                // ציור הילד באופן רקורסיבי
                drawTreeNodesEdges(window, child, childPosition, horizontalSpacing, verticalSpacing, nodeRadius, font, level + 1, totalLevels);
            }
        }
    }
};

template <typename T, size_t K = 2>
class Tree : public BaseTree<T, K> {
public:
    dfs_scan_iterator<T> begin_in_order() {
        return dfs_scan_iterator<T>(this->root);
    }

    dfs_scan_iterator<T> end_in_order() {
        return dfs_scan_iterator<T>(nullptr);
    }

    dfs_scan_iterator<T> begin_pre_order() {
        return dfs_scan_iterator<T>(this->root);
    }

    dfs_scan_iterator<T> end_pre_order() {
        return dfs_scan_iterator<T>(nullptr);
    }

    dfs_scan_iterator<T> begin_post_order() {
        return dfs_scan_iterator<T>(this->root);
    }

    dfs_scan_iterator<T> end_post_order() {
        return dfs_scan_iterator<T>(nullptr);
    }

  
};

template <typename T>
class Tree<T, 2> : public BaseTree<T, 2> {
public:
    in_order_iterator<T> begin_in_order() {
        return in_order_iterator<T>(this->root);
    }

    in_order_iterator<T> end_in_order() {
        return in_order_iterator<T>(nullptr);
    }

    pre_order_iterator<T> begin_pre_order() {
        return pre_order_iterator<T>(this->root);
    }

    pre_order_iterator<T> end_pre_order() {
        return pre_order_iterator<T>(nullptr);
    }

    post_order_iterator<T> begin_post_order() {
        return post_order_iterator<T>(this->root);
    }

    post_order_iterator<T> end_post_order() {
        return post_order_iterator<T>(nullptr);
    }

    make_heap_iterator<T> begin_make_heap() {
        return make_heap_iterator<T>(this->root);
    }

    make_heap_iterator<T> end_make_heap() {
        return make_heap_iterator<T>(nullptr);
    }
};

#endif // TREE_HPP